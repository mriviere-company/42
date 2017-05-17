/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:01:12 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/02 16:01:15 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

# define WIDTH 600
# define HEIGHT 400
# define TEXWIDTH 64;
# define TEXHEIGHT 64;

typedef struct		s_player
{
	int				y;
	int				x;
}					t_player;

typedef struct		s_text
{
	char			*im;
	int				size;
	int				bpp;
	int				endian;
	int				height;
	int				width;
	int				x;
	int				y;
}					t_text;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_text			*text;
	double			oldplanex;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			olddirx;
	double			camerax;
	double			planex;
	double			planey;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				secure;
	int				drawstart;
	int				drawend;
	int				hit;
	int				stepx;
	int				stepy;
	int				mapx;
	int				mapy;
	int				side;
	int				stam;
	int				lineheight;
	char			**map;
	void			*ptri;
	int				bpp;
	int				size;
	int				endian;
	char			*im;
	int				t;
	float			stamina;
	float			staminamax;
}					t_env;

t_env				*ft_put_to_image(t_env *e, int start, int end, int x);
void				ft_calc_raycasting(t_env *e);
void				ft_dda(t_env *e);
void				ft_init_raycasting(t_env *e);
void				ft_init_sidedist(t_env *e);
void				ft_crosshair(t_env *e);
void				ft_crosshair2(t_env *e, int i, int y, int x);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				ft_error(char *error, char *str);
void				ft_draw(t_env *e, int x);
int					ft_texture(t_env *e, int y, int end, int x);
int					ft_draw_wall2(t_env *e, int y, int end, int x);
int					ft_draw_wall1(t_env *e, int y, int end, int x);
int					ft_draw_wall3(t_env *e, int y, int end, int x);
int					ft_draw_wall4(t_env *e, int y, int end, int x);
void				ft_draw_sky_floor(t_env *e, int y, int tmp, int tmpy);
void				ft_move_forward(t_env *e, double movespeed);
void				ft_rotate_camera(t_env *e);
void				ft_door(t_env *e);
void				ft_move_back(t_env *e, double movespeed);
void				ft_rotate_camera2(t_env *e);
void				ft_draw_stamina(t_env *e);
void				ft_init_render(t_env *e);
void				ft_init_env(t_env *e);
void				ft_init_map(t_env *e);
void				ft_init_mlx(t_env *e);
int					texture(t_env *e);
int					uptade(t_env *e);

#endif
