/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:41:20 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/22 02:41:07 by alegrix          ###   ########.fr       */
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
		al_error("malloc struct map");
	game->map->name = argv[1];
	mapchecker(game);
	ff(game);
	game->ins = malloc(sizeof(t_ins));
	if (!game->ins)
		al_error("Malloc struc ins");
	game->ins->mlx = mlx_init();
	if (!game->ins->mlx)
		al_error("Mallox MLX");
	game->ins->win = mlx_new_window
		(game->ins->mlx, game->map->x_s * PX, game->map->y_s * PX, "SL");
	spriting(game);
}

int	key_c(int key_code, t_game *g)
{
	if (key_code == 53)
		mlx_destroy_window(g->ins->mlx, g->ins->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Bad arguments, try this :\n ./so_long file.ber"), 0);
	game = malloc(sizeof(t_game));
	if (!game)
		al_error("malloc struct game");
	malloc_and_mchecker(game, argv);
	display(game);
	mlx_hook(game->ins->win, 2, 1L << 0, closer, game->ins);
	mlx_key_hook(game->ins->win, key_c, game);
	mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param)
	mlx_loop(game->ins->mlx);
}
