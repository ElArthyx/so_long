/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:15:37 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/26 19:25:22 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_body	*last_body(t_game *g)
{
	t_body	*result;

	result = g->snk->body;
	if (result == NULL)
		return (NULL);
	while (result->next != NULL)
		result = result->next;
	return (result);
}

int	size_snk(t_player *p)
{
	t_body	*result;
	int		i;

	result = p->body;
	if (result == NULL)
		return (0);
	i = 1;
	while (result != NULL)
	{
		result = result->next;
		i++;
	}
	return (i);
}

void	flast_bod(t_player *p, t_map *map)
{
	t_body	*tmp;
	t_body	*tmp2;

	tmp = p->body;
	if (tmp == NULL)
		return ;
	if (tmp->next == NULL)
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp;
	tmp = tmp->next;
	tmp2->next = NULL;
	map->con[tmp->y][tmp->x] = '0';
	free(tmp);
}

void	head_bod(t_player *snk, t_game *g)
{
	t_body	*tmp;

	tmp = malloc(sizeof(t_body));
	if (!tmp)
		erro("Alloc body", g);
	tmp->x = snk->h_x;
	tmp->y = snk->h_y;
	tmp->next = snk->body;
	snk->body = tmp;
}
