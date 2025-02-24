/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 03:40:53 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/24 03:51:06 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_game *g)
{
	ft_printf("---------------------------\n");
	ft_printf("GG You won\n%d apples ate\n%d mouvements\n", g->snk->score,
		g->mvm);
	ft_printf("---------------------------\n");
	free_all(g);
}

void	dead(t_game *g)
{
	ft_printf("---------------------------\n");
	ft_printf("You're so bad\n%d apples ate\n%d mouvements\n", g->snk->score,
		g->mvm);
	ft_printf("---------------------------\n");
	free_all(g);
}
