/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:33:11 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/23 03:31:07 by alegrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "libs/minilibx/mlx.h"
# include "libs/minilibx/mlx_int.h"
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
	int		ldir;
	int		score;
	int		h_x;
	int		h_y;
	int		n_x;
	int		n_y;
	t_body	*body;
}			t_player;

typedef struct s_map
{
	char	**content;
	int		is_mcont;
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
	int		mal_win;
	int		mal_mlx;
}			t_ins;

typedef struct s_game
{
	t_map		*map;
	t_ins		*ins;
	t_player	*snk;
	t_sprites	*spt;
	int			mal_ins;
	int			mal_map;
	int			mal_spt;
	int			mvm;
	int			first;
}				t_game;

void	ff(t_game *g);
int		free_array(char **array);
void	al_error(char *name_err, t_game *game);
void	mapchecker(t_game *game);
void	display(t_game *g);
void	spriting(t_game *g);
#endif
