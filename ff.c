/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:11:06 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/24 05:32:55 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill_exit(char **map, int y, int x)
{
	int	result;

	result = 0;
	if (map[y][x] == 'E')
		return (1);
	map[y][x] = 'W';
	if (map[y + 1][x] != 'W')
		result += flood_fill_exit(map, y + 1, x);
	if (map[y - 1][x] != 'W')
		result += flood_fill_exit(map, y - 1, x);
	if (map[y][x + 1] != 'W')
		result += flood_fill_exit(map, y, x + 1);
	if (map[y][x - 1] != 'W')
		result += flood_fill_exit(map, y, x - 1);
	return (result);
}

int	flood_fill_apple(char **map, int y, int x)
{
	int	result;

	result = 0;
	if (map[y][x] == 'A')
	{
		map[y][x] = 'W';
		result++;
	}
	map[y][x] = 'W';
	if (map[y + 1][x] != 'W' && map[y + 1][x] != 'E')
		result += flood_fill_apple(map, y + 1, x);
	if (map[y - 1][x] != 'W' && map[y - 1][x] != 'E')
		result += flood_fill_apple(map, y - 1, x);
	if (map[y][x + 1] != 'W' && map[y][x + 1] != 'E')
		result += flood_fill_apple(map, y, x + 1);
	if (map[y][x - 1] != 'W' && map[y][x - 1] != 'E')
		result += flood_fill_apple(map, y, x - 1);
	return (result);
}

char	**ft_strdup_tab(char **t1, t_game *g)
{
	int		i;
	char	**t2;

	i = 0;
	while (t1[i] != NULL)
		i++;
	t2 = malloc(sizeof(char *) * (i + 1));
	if (!t2)
		al_error("Malloc map temp", g);
	i = 0;
	while (t1[i] != NULL)
	{
		t2[i] = ft_strdup(t1[i]);
		i++;
	}
	t2[i] = NULL;
	return (t2);
}

void	find_head(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map->con[y] != NULL)
	{
		x = 0;
		while (g->map->con[y][x])
		{
			if (g->map->con[y][x] == 'H')
			{
				g->snk->h_y = y;
				g->snk->h_x = x;
			}
			if (g->map->con[y][x] == 'E')
			{
				g->map->xe = x;
				g->map->ye = y;
			}
			x++;
		}
		y++;
	}
}

void	ff(t_game *g)
{
	int		y;
	int		x;
	char	**tmp;

	find_head(g);
	y = g->snk->h_y;
	x = g->snk->h_x;
	tmp = ft_strdup_tab(g->map->con, g);
	if (flood_fill_exit(tmp, y, x) == 0)
		return (free_array(tmp), al_error("Can't join exit", g));
	free_array(tmp);
	tmp = ft_strdup_tab(g->map->con, g);
	if (flood_fill_apple(tmp, y, x) != g->obj)
		return (free_array(tmp), al_error("No all apple accessible", g));
	free_array(tmp);
}
