/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 20:34:10 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 17:30:55 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw(void *mlx, void *win, t_env *e)
{
	if (e->i == 1)
		ft_julia(mlx, win, e, e->fractal);
	else if (e->i == 2)
		ft_mandelbrot(mlx, win, e, e->fractal);
	else if (e->i == 3)
		ft_burning_ship(mlx, win, e, e->fractal);
	return (0);
}

int		ft_check_argv(char *argv)
{
	if (ft_strcmp("julia", argv) == 0)
		return (1);
	if (ft_strcmp("mandelbrot", argv) == 0)
		return (2);
	if (ft_strcmp("burningship", argv) == 0)
		return (3);
	else
		return (0);
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win, e);
	return (0);
}

void	leave_program(void)
{
	ft_putstr("Argument should be:\njulia\nmandelbrot\nburningship\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_env		e;
	t_fractol	fractal;

	e.i = 0;
	e = init_env(e);
	e.fractal = init_fractal(&fractal);
	if (argc == 2)
	{
		init(&e, argv[1]);
		if (e.i > 0)
		{
			e = ft_im(e);
			mlx_mouse_hook(e.win, mouse, &e);
			mlx_hook(e.win, MN, PMM, mouse_hook, &e);
			mlx_gest(&e);
		}
		else
			leave_program();
	}
	else
		leave_program();
	return (0);
}
