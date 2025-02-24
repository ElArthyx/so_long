/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:41:20 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/24 05:49:13 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/minilibx/mlx.h"
#include "so_long.h"

void	malloc_and_mchecker(t_game *game, char **argv)
{
	game->map = ft_calloc(1, sizeof(t_map));
	if (!(game->map))
		al_error("malloc struct map", game);
	game->mal_map = 1;
	game->map->name = argv[1];
	game->snk = ft_calloc(sizeof(t_player), 1);
	if (!game->snk)
		al_error("Malloc player", game);
	game->mal_pla = 1;
	game->first = 1;
	mapchecker(game);
	ff(game);
	game->ins = ft_calloc(sizeof(t_ins), 1);
	if (!game->ins)
		al_error("Malloc struc ins", game);
	game->mal_ins = 1;
	game->ins->mlx = mlx_init();
	if (!game->ins->mlx)
		al_error("Mallox MLX", game);
	game->ins->mal_mlx = 1;
	game->ins->win = mlx_new_window
		(game->ins->mlx, game->map->x_s * PX, (game->map->y_s + 1) * PX, "SL");
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
		return (gcontent(g, g->snk, g->map), g->block = 1, g->cur_fps = 10, 0);
	}
	else if (keyc == XK_s)
	{
		g->snk->dir = SOUTH;
		return (gcontent(g, g->snk, g->map), g->block = 1, g->cur_fps = 10, 0);
	}
	else if (keyc == XK_d)
	{
		g->snk->dir = EAST;
		return (gcontent(g, g->snk, g->map), g->block = 1, g->cur_fps = 10, 0);
	}
	else if (keyc == XK_a)
	{
		g->snk->dir = WEST;
		return (gcontent(g, g->snk, g->map), g->block = 1, g->cur_fps = 10, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error\nBad args, try :\n./so_long file.ber"), 0);
	game = ft_calloc(sizeof(t_game), 1);
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
