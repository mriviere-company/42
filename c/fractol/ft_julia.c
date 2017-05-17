/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:07:47 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 17:56:13 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_loop(t_fractol *fractol)
{
	while (((fractol->z_r * fractol->z_r) + (fractol->z_i * fractol->z_i)) < 4
		&& fractol->i < fractol->iteration_max)
	{
		fractol->tmp = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r - fractol->z_i *
						fractol->z_i + fractol->c_r;
		fractol->z_i = 2 * fractol->z_i * fractol->tmp + fractol->c_i;
		fractol->i++;
	}
}

void	ft_calc_julia(t_fractol fractol, t_env *e)
{
	while (fractol.y < WIDTH)
	{
		while (fractol.x < HEIGHT)
		{
			fractol.c_r = (double)((e->x * 4) / WIDTH) - 2;
			fractol.c_i = (double)((e->y * 4) / HEIGHT) - 2;
			fractol.z_r = (fractol.x - (WIDTH / 2)) /
							fractol.zoom + fractol.x1;
			fractol.z_i = (fractol.y - (HEIGHT / 2)) /
							fractol.zoom + fractol.y1;
			fractol.i = 0;
			julia_loop(&fractol);
			if (fractol.i == fractol.iteration_max)
				e = ft_put_to_image(e, &fractol);
			else
				e = ft_put_blue_image(e, &fractol);
			fractol.x++;
		}
		fractol.x = 0;
		fractol.y++;
	}
}

void	ft_julia(void *mlx, void *win, t_env *e, t_fractol *fractol)
{
	mlx_clear_window(e->mlx, e->win);
	ft_bzero(e->im, e->size * HEIGHT);
	ft_calc_julia(*fractol, e);
	mlx_put_image_to_window(mlx, win, e->ptri, 0, 0);
}
