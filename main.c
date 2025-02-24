/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:41:20 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/24 02:26:01 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/minilibx/mlx.h"
#include "so_long.h"
#include <stdlib.h>

int	closer(t_ins *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	malloc_and_mchecker(t_game *game, char **argv)
{
	game->map = malloc(sizeof(t_map));
	if (!(game->map))
		al_error("malloc struct map", game);
	game->mal_map = 1;
	game->map->name = argv[1];
	game->snk = malloc(sizeof(t_player));
	if (!game->snk)
		exit(1);
	game->first = 1;
	mapchecker(game);
	ff(game);
	game->ins = malloc(sizeof(t_ins));
	if (!game->ins)
		al_error("Malloc struc ins", game);
	game->mal_ins = 1;
	game->ins->mlx = mlx_init();
	if (!game->ins->mlx)
		al_error("Mallox MLX", game);
	game->ins->mal_mlx = 1;
	game->ins->win = mlx_new_window
		(game->ins->mlx, game->map->x_s * PX, game->map->y_s * PX, "SL");
	game->ins->mal_win = 1;
	spriting(game);
}

int	key_c(int keyc, t_game *g)
{
	if (keyc == XK_Escape)
		free_all(g);
	else if (keyc == XK_w)
	{
		g->snk->dir = NORTH;
		gcontent(g, g->snk, g->map);
		g->block = 1;
		g->cur_fps = 10;
	}
	else if (keyc == XK_s)
	{
		g->snk->dir = SOUTH;
		gcontent(g, g->snk, g->map);
		g->block = 1;
		g->cur_fps = 10;
	}
	else if (keyc == XK_d)
	{
		g->snk->dir = EAST;
		gcontent(g, g->snk, g->map);
		g->block = 1;
		g->cur_fps = 10;
	}
	else if (keyc == XK_a)
	{
		g->snk->dir = WEST;
		gcontent(g, g->snk, g->map);
		g->block = 1;
		g->cur_fps = 10;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error\nBad args, try :\n./so_long file.ber"), 0);
	game = malloc(sizeof(t_game));
	if (!game)
		al_error("malloc struct game", game);
	malloc_and_mchecker(game, argv);
	display(game);
	game->block = 0;
	mlx_hook(game->ins->win, 17, 0, free_all, game);
	mlx_hook(game->ins->win, 2, KeyPressMask, key_c, game);
	mlx_loop_hook(game->ins->mlx, gclock, game);
	mlx_loop(game->ins->mlx);
}
