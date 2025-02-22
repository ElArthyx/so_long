/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:22:52 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/21 00:25:51 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_array(char **array)
{
	int	index;

	if (!array)
		return (0);
	index = 0;
	while (array[index])
		free(array[index++]);
	free(array);
	return (0);
}

void	al_error(char *name_err)
{
	ft_printf("Error\n%s\n", name_err);
	exit(1);
}
