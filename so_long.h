/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegrix <alegrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:33:11 by alegrix           #+#    #+#             */
/*   Updated: 2025/02/26 21:52:54 by alegrix          ###   ########.fr       */
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
# include <X11/Xutil.h>
# include <X11/keysym.h>

# define L_OBJECT "0WEHAK"
# define FPS 120
# define PX 32
# define EAST 1
# define WEST 3
# define NORTH 2
# define SOUTH 4

# define W 13
# define D 2
# define S 1
# define A 0
# define ESC 53

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
	t_img	*eo;
	t_img	*p;
	t_img	*a;
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
	char	**con;
	int		is_mcont;
	int		has_exit;
	int		has_start;
	int		app;
	int		fd;
	char	*name;
	int		xe;
	int		ye;
	int		x_s;
	int		y_s;
	int		yap;
	int		xap;
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
	int			mal_pla;
	int			mvm;
	int			first;
	int			cur_fps;
	int			block;
	int			obj;
}				t_game;

void	ff(t_game *g);
void	free_array(char **array);
void	erro(char *name_err, t_game *game);
void	mapchecker(t_game *game);
void	display(t_game *g);
void	spriting(t_game *g);
void	head_bod(t_player *snk, t_game *g);
int		size_snk(t_player *p);
void	giv_app(t_map *map);
void	flast_bod(t_player *p, t_map *map);
int		gclock(t_game *g);
int		free_all(t_game *g);
void	gcontent(t_game *g, t_player *s, t_map *m);
void	dead(t_game *g);
void	win(t_game *g);
#endif
