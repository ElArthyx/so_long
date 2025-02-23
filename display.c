/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:53:17 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/23 03:32:41 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spriting(t_game *g)
{
	int	w;
	int	l;

	g->spt = malloc(sizeof(t_sprites));
	if (!g->spt)
		al_error("Sprites alloc", g);
	g->mal_spt = 1;
	g->spt->h_e = mlx_xpm_file_to_image(g->ins->mlx, "sprt/h_e.xpm", &w, &l);
	g->spt->h_n = mlx_xpm_file_to_image(g->ins->mlx, "sprt/h_n.xpm", &w, &l);
	g->spt->h_w = mlx_xpm_file_to_image(g->ins->mlx, "sprt/h_w.xpm", &w, &l);
	g->spt->h_s = mlx_xpm_file_to_image(g->ins->mlx, "sprt/h_s.xpm", &w, &l);
	g->spt->w = mlx_xpm_file_to_image(g->ins->mlx, "sprt/w.xpm", &w, &l);
	g->spt->p = mlx_xpm_file_to_image(g->ins->mlx, "sprt/gpple.xpm", &w, &l);
	g->spt->back = mlx_xpm_file_to_image(g->ins->mlx, "sprt/back.xpm", &w, &l);
	g->spt->ex = mlx_xpm_file_to_image(g->ins->mlx, "sprt/ex.xpm", &w, &l);
	g->spt->t_s = mlx_xpm_file_to_image(g->ins->mlx, "sprt/t_s.xpm", &w, &l);
	g->spt->t_n = mlx_xpm_file_to_image(g->ins->mlx, "sprt/t_n.xpm", &w, &l);
	g->spt->t_w = mlx_xpm_file_to_image(g->ins->mlx, "sprt/t_w.xpm", &w, &l);
	g->spt->t_e = mlx_xpm_file_to_image(g->ins->mlx, "sprt/t_e.xpm", &w, &l);
	g->spt->b = mlx_xpm_file_to_image(g->ins->mlx, "sprt/b.xpm", &w, &l);
}

void	iditing2(char c, t_game *g, int y, int x)
{
	if (c == '6')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->t_s, x, y);
	else if (c == '5')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->t_w, x, y);
	else if (c == '4')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->t_e, x, y);
	else if (c == '3')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->t_n, x, y);
}

void	iditing(char c, t_game *g, int y, int x)
{
	if (c == 'W')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->w, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->ex, x, y);
	else if (c == '0')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->back, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->p, x, y);
	else if (c == '9')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->h_s, x, y);
	else if (c == '8')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->h_w, x, y);
	else if (c == 'H')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->h_e, x, y);
	else if (c == '7')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->h_n, x, y);
	else if (c == 'B')
		mlx_put_image_to_window(g->ins->mlx, g->ins->win, g->spt->b, x, y);
	else
		iditing2(c, g, y, x);
}

void	display(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map->content[y] != NULL)
	{
		x = 0;
		while (g->map->content[y][x])
		{
			iditing(g->map->content[y][x], g, y * 32, x * 32);
			x++;
		}
		y++;
	}
}
