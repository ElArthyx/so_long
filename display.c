/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:53:17 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/24 05:12:08 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spriting(t_game *g)
{
	int	w;
	int	l;

	g->spt = ft_calloc(1, sizeof(t_sprites));
	if (!g->spt)
		al_error("Sprites alloc", g);
	g->mal_spt = 1;
	g->spt->h_e = mlx_xpm_file_to_image(g->ins->mlx, "sprt/h_e.xpm", &w, &l);
	g->spt->h_n = mlx_xpm_file_to_image(g->ins->mlx, "sprt/h_n.xpm", &w, &l);
	g->spt->h_w = mlx_xpm_file_to_image(g->ins->mlx, "sprt/h_w.xpm", &w, &l);
	g->spt->h_s = mlx_xpm_file_to_image(g->ins->mlx, "sprt/h_s.xpm", &w, &l);
	g->spt->w = mlx_xpm_file_to_image(g->ins->mlx, "sprt/w.xpm", &w, &l);
	g->spt->p = mlx_xpm_file_to_image(g->ins->mlx, "sprt/gpple.xpm", &w, &l);
	g->spt->a = mlx_xpm_file_to_image(g->ins->mlx, "sprt/apple.xpm", &w, &l);
	g->spt->back = mlx_xpm_file_to_image(g->ins->mlx, "sprt/back.xpm", &w, &l);
	g->spt->ex = mlx_xpm_file_to_image(g->ins->mlx, "sprt/ex.xpm", &w, &l);
	g->spt->eo = mlx_xpm_file_to_image(g->ins->mlx, "sprt/kayou.xpm", &w, &l);
	g->spt->b = mlx_xpm_file_to_image(g->ins->mlx, "sprt/b.xpm", &w, &l);
}

void	iditing(char c, t_game *g, int y, int x)
{
	if (c == 'W')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->w, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->eo, x, y);
	else if (c == 'O')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->ex, x, y);
	else if (c == '0')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->back, x, y);
	else if (c == 'A')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->a, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->p, x, y);
	else if (c == 'H' && g->snk->ldir == SOUTH)
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->h_s, x, y);
	else if (c == 'H' && g->snk->ldir == WEST)
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->h_w, x, y);
	else if (c == 'H' && g->snk->ldir == NORTH)
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->h_n, x, y);
	else if (c == 'H')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->h_e, x, y);
	else if (c == 'B')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->b, x, y);
}

static void	dis_score(t_game *g)
{
	int		i;
	char	*tmp;
	char	*result;

	tmp = ft_itoa(g->mvm);
	result = ft_strjoin("Mouv :", tmp);
	free(tmp);
	i = -1;
	while (++i <= g->map->x_s)
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->back,
			i * PX, (g->map->y_s) * PX);
	mlx_string_put(g->ins->mlx, g->ins->win,
		PX - 1, ((g->map->y_s + 1) * PX) - 15, 0x000000, result);
	mlx_string_put(g->ins->mlx, g->ins->win,
		PX, ((g->map->y_s + 1) * PX) - 16, 0xFFFFFF, result);
	free(result);
	tmp = ft_itoa(g->snk->score);
	result = ft_strjoin("Score :", tmp);
	free(tmp);
	mlx_string_put(g->ins->mlx, g->ins->win,
		PX - 1, ((g->map->y_s + 1) * PX) - 2, 0x000000, result);
	mlx_string_put(g->ins->mlx, g->ins->win,
		PX, ((g->map->y_s + 1) * PX) - 1, 0xFFFFFF, result);
	free(result);
}

void	display(t_game *g)
{
	int		y;
	int		x;

	y = 0;
	while (g->map->con[y] != NULL)
	{
		x = 0;
		while (g->map->con[y][x] != '\n')
		{
			iditing(g->map->con[y][x], g, y * 32, x * 32);
			x++;
		}
		y++;
	}
	dis_score(g);
}
