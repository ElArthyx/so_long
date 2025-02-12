/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:41:20 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/12 07:27:32 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	malloc_and_mchecker(t_game *game, char **argv)
{
	game->map = malloc(sizeof(t_map));
	if (!(game->map))
		al_error("malloc struct map");
	game->map->name = argv[1];
	mapchecker(game);
	game->ins = malloc(sizeof(t_ins));
	if (!game->ins)
		al_error("Malloc struc ins");
	game->ins->mlx = mlx_init();
	if (!game->ins->mlx)
		al_error("Mallox MLX");
	game->ins->win = mlx_new_window
		(game->ins->mlx, game->map->x_s * PX, game->map->y_s * PX, "So_Long");
	spriting(game);
	while (1)
		display(game);
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
}
