/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:33:11 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/16 02:14:48 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "libs/minilibx-linux/mlx.h"
# include "libs/minilibx-linux/mlx_int.h"
# include "libs/libft/libft.h"
# include "libs/libft/ft_printf/ft_printf.h"

# define L_OBJECT "0WEHP"
# define FPS 4
# define PX 32
# define EAST 1
# define WEST 3
# define NORTH 2
# define SOUTH 4

typedef struct s_sprites
{
	int		is_malloc;
	t_img	*back;
	t_img	*w;
	t_img	*h_e;
	t_img	*h_n;
	t_img	*h_s;
	t_img	*h_w;
	t_img	*b;
	t_img	*ex;
	t_img	*t_e;
	t_img	*t_n;
	t_img	*t_w;
	t_img	*t_s;
	t_img	*p;
}			t_sprites;

typedef struct s_body
{
	int				x;
	int				y;
	struct s_body	*next;
}					t_body;

typedef struct s_player
{
	int		dir;
	int		pdir;
	int		score;
	int		nbmov;
	int		h_x;
	int		h_y;
	t_body	*body;
}			t_player;

typedef struct s_map
{
	char	**content;
	int		is_malloc;
	int		has_exit;
	int		has_start;
	int		app;
	int		fd;
	char	*name;
	int		x_s;
	int		y_s;
}			t_map;

typedef struct s_ins
{
	void	*mlx;
	void	*win;
}			t_ins;

typedef struct s_game
{
	t_map		*map;
	t_ins		*ins;
	t_player	*snake;
	t_sprites	*spt;
}				t_game;

void	al_error(char *name_err);
void	mapchecker(t_game *game);
void	display(t_game *g);
void	spriting(t_game *g);
#endif
