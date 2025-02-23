/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:47:10 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/23 21:37:37 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_act(t_game *g)
{
	t_body	*tmp;
	int		y;
	int		x;

	g->map->con[g->snk->h_y][g->snk->h_x] = 'H';
	y = 0;
	tmp = g->snk->body;
	while (tmp != NULL)
		g->map->con[tmp->y][tmp->x] = 'B';
	if (g->map->app == 0)
		giv_app(g->map);
	if (g->snk->score == 1)
		g->map->con[g->map->ye][g->map->xe] = 'O';
}

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

void	gfirst(t_game *g, t_player *s, t_map *m)
{
	if (s->dir == 0)
		return ;
	head_bod(s, g);
	mouv(g);
	if (m->con[s->n_y][s->n_x] != 'P')
		flast_bod(g->snk, g->map);
	else
		s->score++;
	if (m->con[s->n_y][s->n_x] == 'W' || m->con[s->n_y][s->n_x] == 'B' ||
		m->con[s->n_y][s->n_x] == 'E')
		dead(g);
	s->h_x = s->n_x;
	s->h_y = s->n_y;
	g->mvm++;
	map_act(g);
}

void	gcontent(t_game *g, t_player *s, t_map *m)
{
	usleep(1000000 / FPS);
	if (g->first == 1)
		gfirst(g, s, m);
	else
	{
		head_bod(s, g);
		mouv(g);
		if (m->con[s->n_y][s->n_x] != 'P' && s->score != size_snk(s) - 2)
			flast_bod(g->snk, g->map);
		else
			g->snk->score++;
		if (m->con[s->n_y][s->n_x] == 'W' || m->con[s->n_y][s->n_x] == 'B' ||
			m->con[s->n_y][s->n_x] == 'E')
			dead(g);
		g->snk->h_x = g->snk->n_x;
		g->snk->h_y = g->snk->n_y;
		g->mvm++;
		map_act(g);
	}
}

int	gclock(t_game *g)
{
	gcontent(g, g->snk, g->map);
	return (0);
}
