/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:09:40 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 16:48:41 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_gest(t_env *e)
{
	mlx_hook(e->win, 2, 1, key_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}

t_env		init_env(t_env e)
{
	e.i = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "fractol");
	e.frequency = 0.1;
	e.color = 4;
	return (e);
}

t_env		ft_im(t_env e)
{
	e.ptri = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.im = mlx_get_data_addr(e.ptri, &e.bpp, &e.size, &e.endian);
	return (e);
}

t_fractol	*init_fractal(t_fractol *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->x1 = 0;
	fractal->y1 = 0;
	fractal->zoom = 150;
	fractal->iteration_max = 50;
	return (fractal);
}

void		init(t_env *e, char *str)
{
	e->argv = str;
	e->zoomx = 1.0;
	e->decy1 = 0;
	e->decy2 = 0;
	e->decx1 = 0;
	e->decx2 = 0;
	e->i = ft_check_argv(e->argv);
}
