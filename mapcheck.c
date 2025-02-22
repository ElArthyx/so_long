/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 01:28:18 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/21 00:51:35 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	check_border(t_map *map)
{
	int	line;
	int	col;

	line = 0;
	while (map->content[line] != NULL)
	{
		col = 0;
		while (map->content[line][col] && map->content[line][col] != '\n')
		{
			if (line == 0 || line == map->y_s
				|| col == 0 || col == map->x_s)
				if (map->content[line][col] != 'W')
					al_error("Border need full Wall");
			col++;
		}
		line++;
	}
}

void	check_line_content(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (ft_strchr(L_OBJECT, line[i]) == NULL)
		{
			ft_printf("%c", line[i]);
			free(line);
			al_error("Bad char in file.ber");
		}
		if (line[i] == 'E')
			map->has_exit += 1;
		else if (line[i] == 'H')
			map->has_start += 1;
		else if (line[i] == 'P')
			map->app += 1;
		i++;
	}
	if (map->has_exit > 1 || map->has_start > 1)
	{
		free(line);
		al_error("There is more than 1 exit or 1 start or not item");
	}
}

void	check_map_form(t_map *map)
{
	char	*line;
	int		i;

	line = get_next_line(map->fd);
	if (line == NULL)
		al_error("Empty file");
	map->x_s = ft_strlen(line) - 1;
	map->content = malloc(sizeof(char *) * (map->y_s + 1));
	if (!map->content)
		exit(2);
	i = 0;
	while (line[0] != '\0')
	{
		if (ft_strchr(line, '\n') == NULL)
			line = ft_strjoin(line, "\n");
		if (map->x_s != (int)ft_strlen(line) - 1)
			al_error("The map isn't a rectangle");
		check_line_content(map, line);
		map->content[i++] = line;
		line = get_next_line(map->fd);
	}
	map->content[i] = NULL;
	if (map->app < 1)
		al_error("Not item");
}

void	check_file_name(t_map *map)
{
	char	*temp;

	temp = map->name;
	if (temp == NULL)
		al_error("No file.ber");
	while (*(temp + 4) != '\0')
		temp++;
	if (ft_strncmp(temp, ".ber", 4) != 0)
		al_error("File extension, try this :\n ./so_long file.ber");
	map->fd = open(map->name, O_RDONLY);
	if (map->fd == -1)
		al_error("The file.ber was not found");
	temp = get_next_line(map->fd);
	while (temp != NULL && temp[0] != '\0')
	{
		free(temp);
		map->y_s++;
		temp = get_next_line(map->fd);
	}
	close(map->fd);
}

void	mapchecker(t_game *game)
{
	check_file_name(game->map);
	game->map->fd = open(game->map->name, O_RDONLY);
	if (game->map->fd == -1)
		al_error("Open fd");
	check_map_form(game->map);
	close(game->map->fd);
	check_border(game->map);
}
