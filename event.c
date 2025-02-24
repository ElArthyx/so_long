/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:47:10 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/24 04:37:25 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_act(t_game *g)
{
	t_body	*tmp;

	tmp = g->snk->body;
	while (tmp != NULL)
	{
		g->map->con[tmp->y][tmp->x] = 'B';
		tmp = tmp->next;
	}
	g->map->con[g->snk->h_y][g->snk->h_x] = 'H';
	if (g->map->app <= 0 && g->snk->score >= g->obj)
		giv_app(g->map);
	if (g->snk->score >= g->obj)
		g->map->con[g->map->ye][g->map->xe] = 'O';
}

void	mouv(t_game *g)
{
	g->mvm++;
	ft_printf("Nb mouvement : %d\n", g->mvm);
	g->snk->n_x = g->snk->h_x;
	g->snk->n_y = g->snk->h_y;
	if (g->snk->ldir == EAST)
		g->snk->n_x++;
	else if (g->snk->ldir == WEST)
		g->snk->n_x--;
	else if (g->snk->ldir == NORTH)
		g->snk->n_y--;
	else if (g->snk->ldir == SOUTH)
		g->snk->n_y++;
}

void	gfirst(t_game *g, t_player *s, t_map *m)
{
	if (s->dir == 0)
		return ;
	head_bod(s, g);
	s->ldir = s->dir;
	mouv(g);
	if (m->con[s->n_y][s->n_x] != 'P' && m->con[s->n_y][s->n_x] != 'A')
		flast_bod(g->snk, g->map);
	else
	{
		s->score++;
		m->app--;
	}
	if (m->con[s->n_y][s->n_x] == 'W' || m->con[s->n_y][s->n_x] == 'E')
		dead(g);
	if (m->con[s->n_y][s->n_x] == 'O')
		win(g);
	s->h_x = s->n_x;
	s->h_y = s->n_y;
	display(g);
	g->first = 0;
}

void	gcontent(t_game *g, t_player *s, t_map *m)
{
	if (g->first == 1)
		gfirst(g, s, m);
	else
	{
		head_bod(s, g);
		s->ldir = s->dir;
		mouv(g);
		if (m->con[s->n_y][s->n_x] != 'P' && m->con[s->n_y][s->n_x] != 'A')
			flast_bod(g->snk, g->map);
		else
		{
			g->snk->score++;
			m->app--;
		}
		if (m->con[s->n_y][s->n_x] == 'W' || m->con[s->n_y][s->n_x] == 'E')
			dead(g);
		if (m->con[s->n_y][s->n_x] == 'O')
			win(g);
		g->snk->h_x = g->snk->n_x;
		g->snk->h_y = g->snk->n_y;
		map_act(g);
		display(g);
	}
}

int	gclock(t_game *g)
{
	usleep(1000000 / FPS);
	g->cur_fps++;
	if (g->cur_fps % 30 == 0)
	{
		if (g->block == 0)
			gcontent(g, g->snk, g->map);
		else
			g->block = 0;
	}
	return (0);
}
