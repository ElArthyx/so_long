/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:51:56 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/23 20:36:26 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rnd(int nb)
{
	int		r;
	int		is_good;

	is_good = 0;
	while (is_good == 0)
	{
		r = rand();
		r = r % nb;
		if (r != 0)
			is_good = 1;
	}
	return (r);
}

void	giv_app(t_map *map)
{
	map->xap = rnd(map->x_s);
	map->yap = rnd(map->y_s);
	while (map->con[map->yap][map->xap] != '0')
	{
		map->yap = rnd(map->y_s);
		map->xap = rnd(map->x_s);
	}
	map->con[map->yap][map->xap] = 'P';
	map->app++;
}
