/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:51:56 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/28 20:02:43 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnjoin(char *line)
{
	char	*tmp;

	tmp = ft_strjoin(line, "\n");
	free(line);
	return (tmp);
}

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
	int	count;

	map->xap = rnd(map->x_s);
	map->yap = rnd(map->y_s);
	count = 0;
	while (map->con[map->yap][map->xap] != '0')
	{
		map->yap = rnd(map->y_s);
		map->xap = rnd(map->x_s);
		count++;
		if (count > 5)
			return ;
	}
	map->con[map->yap][map->xap] = 'P';
	map->app = 1;
}
