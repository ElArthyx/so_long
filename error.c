/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:22:52 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/23 21:58:42 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	index;

	if (!array)
		return ;
	index = 0;
	while (array[index])
		free(array[index++]);
	free(array);
}

void	free_sprt(t_game *g)
{
	if (g->mal_spt == 1)
	{
		mlx_destroy_image(g->ins->mlx, g->spt->b);
		mlx_destroy_image(g->ins->mlx, g->spt->p);
		mlx_destroy_image(g->ins->mlx, g->spt->w);
		mlx_destroy_image(g->ins->mlx, g->spt->ex);
		mlx_destroy_image(g->ins->mlx, g->spt->h_e);
		mlx_destroy_image(g->ins->mlx, g->spt->h_n);
		mlx_destroy_image(g->ins->mlx, g->spt->h_s);
		mlx_destroy_image(g->ins->mlx, g->spt->h_w);
		mlx_destroy_image(g->ins->mlx, g->spt->eo);
		mlx_destroy_image(g->ins->mlx, g->spt->back);
		free(g->spt);
	}
}

int	free_all(t_game *g)
{
	if (g->mal_map == 1)
	{
		if (g->map->is_mcont == 1)
			free_array(g->map->con);
		free(g->map);
	}
	free_sprt(g);
	if (g->mal_ins == 1)
	{
		if (g->ins->mal_win)
			mlx_destroy_window(g->ins->mlx, g->ins->win);
		if (g->ins->mal_mlx)
			mlx_destroy_display(g->ins->mlx);
		free(g->ins);
	}
	free(g);
	return (1);
}

void	al_error(char *name_err, t_game *g)
{
	ft_printf("Error\n%s\n", name_err);
	free_all(g);
}
