/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:47:10 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/23 03:22:55 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mouv(t_game *g)
{
	g->snk->n_x = g->snk->h_x;
	g->snk->n_y = g->snk->h_y;
	if (g->snk->dir == EAST)
		g->snk->n_x++;
	else if (g->snk->dir == WEST)
		g->snk->n_x--;
	else if (g->snk->dir == NORTH)
		g->snk->n_y--;
	else if (g->snk->dir == SOUTH)
		g->snk->n_y++;
}

void	head_bod(t_player *snk, t_game *g)
{
	t_body	*tmp;

	tmp = malloc(sizeof(t_body));
	if (!tmp)
		al_error("Alloc body", g);
	tmp->x = snk->h_x;
	tmp->y = snk->h_y;
	tmp->next = snk->body;
	snk->body = tmp;
}

void	gfirst(t_game *g)
{
	if (g->snk->dir == 0)
		return ;
	mouv(g);

}

void	gclock(t_game *g)
{
	usleep(1000000 / FPS);
	if (g->first == 1)
		gfirst(g);
	else
	{
		mouv(g);
		if (g->map->content[g->snk->n_y][g->snk->n_x] != 'P')
			free(last_body(g));
		if (g->map->content[g->snk->n_y][g->snk->n_x] == 'W' ||
			g->map->content[g->snk->n_y][g->snk->n_x] == 'B' )
			dead(g);
		g->snk->h_x = g->snk->n_x;
		g->snk->h_y = g->snk->n_y;
		g->mvm++;
	}
}
