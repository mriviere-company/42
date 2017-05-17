/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:07:11 by mriviere          #+#    #+#             */
/*   Updated: 2016/10/20 14:58:12 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

# define PI 3.141592654

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			un;
	double			a1;
	double			a2;
	double			a3;
	double			a4;
	double			b1;
	double			b2;
	double			b3;
	double			b4;
	double			c1;
	double			c2;
	double			c3;
	double			c4;
	double			d1;
	double			d2;
	double			d3;
	double			d4;
	double			degx;
	double			degy;
	double			mapx;
	double			mapy;
	double			new_x;
	double			new_y;
	int				x_tmp;
	int				y_tmp;
	double			vecdir_x;
	double			vecdir_y;
	double			zoom;
	double			h;
	double			dec;
	int				size;
	double			w;
	int				inc;
}					t_point;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_point2d
{
	int				x;
	int				y;
}					t_point2d;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**map;
	void			*ptri;
	int				bpp;
	int				size;
	int				z;
	int				endian;
	char			*im;
	t_point			point;
	t_coord			coord;
}					t_env;

void				ft_error(char *error, char *str);
void				ft_check_z(t_env *e);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				ft_add_int(int t, char *buffer, t_env *e);
int					ft_nb_space(char *buffer);
void				ft_parse(char *argument, int i, t_env *e);
t_point				rotation_y(t_point l);
t_point				matrice_y(t_point list);
t_point				rotation_x(t_point l);
t_point				matrice_x(t_point list);
t_env				*ft_go_image_next(t_env *e, int x, int y, int color);
t_env				*ft_go_image(t_env *e, int x, int y, int color);
void				ft_print_bresenham(t_point2d a, t_point2d b, t_env *e);
void				ft_bresenham(t_point2d a, t_point2d b, t_env *e);
void				ft_next_3d_place(t_point2d a, t_point2d b,
					t_env *e);
void				ft_3d_place(t_env *e);
int					draw(t_env *e);
void				ft_put_in_tab(char *argument, t_env *e);
#endif
