/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:52:43 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 18:41:52 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# define WIDTH 800
# define HEIGHT 800
# define PMM (1L<<6)
# define MN 6
# define PI 3.14159265359

typedef	struct	s_fractol
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	float	zoom;
	int		image_x;
	int		image_y;
	float	iteration_max;
	double	x;
	double	y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		i;
	double	tmp;
}				t_fractol;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	void		*ptri;
	int			size;
	int			bpp;
	int			endian;
	char		*im;
	int			i;
	char		*argv;
	int			x;
	int			y;
	double		decx1;
	double		decx2;
	double		decy1;
	double		decy2;
	double		zoomx;
	float		zoom;
	int			ite_zoom;
	double		frequency;
	int			color;
	t_fractol	*fractal;
}				t_env;

void			mlx_gest(t_env *e);
t_env			init_env(t_env e);
t_fractol		*init_fractal(t_fractol *fractal);
t_env			ft_im(t_env e);
int				draw(void *mlx, void *win, t_env *e);
int				mouse(const int b, int x, int y, t_env *e);
void			ft_mandelbrot(void *mlx, void *win, t_env *e,
							t_fractol *fractol);
void			ft_julia(void *mlx, void *win, t_env *e, t_fractol *fractol);
void			ft_burning_ship(void *mlx, void *win, t_env *e,
							t_fractol *fractol);
t_env			*ft_put_to_image(t_env *e, t_fractol *fractol);
t_env			*ft_put_blue_image(t_env *e, t_fractol *fractol);
t_env			*ft_reni(t_env *e);
void			init(t_env *e, char *str);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int x, int y, t_env *e);
int				expose_hook(t_env *e);
int				ft_check_argv(char *argv);
void			ft_up(t_env *e);
void			ft_down(t_env *e);
void			ft_left(t_env *e);
void			ft_right(t_env *e);

#endif
