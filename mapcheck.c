/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:28:18 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/26 22:03:15 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/libft/libft.h"
#include "so_long.h"
#include <unistd.h>

void	check_border(t_map *map, t_game *g)
{
	int	l;
	int	col;

	l = 0;
	while (map->con[l] != NULL)
	{
		col = 0;
		while (map->con[l][col] && map->con[l][col] != '\n')
		{
			if (l == 0 || l == map->y_s || col == 0 || col == map->x_s - 1)
				if (map->con[l][col] != 'W')
					erro("Border need full Wall", g);
			col++;
		}
		l++;
	}
}

void	check_line_content(t_map *map, char *line, t_game *g)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (ft_strchr(L_OBJECT, line[i]) == NULL)
		{
			free(line);
			get_next_line(-1);
			erro("Bad char in file.ber", g);
		}
		if (line[i] == 'E')
			map->has_exit += 1;
		else if (line[i] == 'H')
			map->has_start += 1;
		else if (line[i] == 'A')
			g->obj += 1;
		i++;
	}
	if (map->has_exit > 1 || map->has_start > 1)
	{
		free(line);
		get_next_line(-1);
		erro("There is more than 1 exit or 1 start", g);
	}
}

void	check_map_form(t_map *map, t_game *g)
{
	char	*line;
	int		i;

	line = get_next_line(map->fd);
	if (line == NULL)
		erro("Empty file", g);
	map->x_s = ft_strlen(line) - 1;
	map->con = ft_calloc(sizeof(char *), map->y_s + 1);
	if (!map->con)
		erro("malloc content", g);
	map->is_mcont = 1;
	i = 0;
	while (line[0] != '\0')
	{
		if (ft_strchr(line, '\n') == NULL)
			line = ft_strjoin(line, "\n");
		if (map->x_s != (int)ft_strlen(line) - 1)
			return (get_next_line(-1), free(line), erro("Map isn't good", g));
		check_line_content(map, line, g);
		map->con[i++] = line;
		line = get_next_line(map->fd);
	}
	if (g->obj < 1)
		return (free(line), get_next_line(-1), erro("Not item", g));
	return (map->con[i] = NULL, free(line));
}

void	check_file_name(t_map *map, t_game *g)
{
	char	*temp;

	temp = map->name;
	if (temp == NULL)
		erro("No file.ber", g);
	while (*(temp + 4) != '\0')
		temp++;
	if (ft_strncmp(temp, ".ber", 4) != 0)
		erro("File extension, try this :\n./so_long file.ber", g);
	map->fd = open(map->name, O_RDONLY);
	if (map->fd == -1)
		erro("The file.ber was not found", g);
	temp = get_next_line(map->fd);
	while (temp != NULL && temp[0] != '\0')
	{
		free(temp);
		map->y_s++;
		temp = get_next_line(map->fd);
	}
	free(temp);
	close(map->fd);
}

void	mapchecker(t_game *game)
{
	check_file_name(game->map, game);
	game->map->fd = open(game->map->name, O_RDONLY);
	if (game->map->fd == -1)
		erro("Open fd", game);
	check_map_form(game->map, game);
	close(game->map->fd);
	check_border(game->map, game);
}
