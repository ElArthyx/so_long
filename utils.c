/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:51:56 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/12 00:52:17 by alegrix          ###   ########.fr       */
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

void	give_item_pos(t_item *item, t_map *map, char l)
{
	item->x_p = rnd(map->x_s);
	item->y_p = rnd(map->y_s);
	while (map->content[item->y_p][item->x_p] != '0')
	{
		item->y_p = rnd(map->x_s);
		item->x_p = rnd(map->x_s);
	}
	map->content[item->y_p][item->x_p] = l;
}
