/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:04:01 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 15:24:17 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_loop(t_fractol *fractol)
{
	while (((fractol->z_r * fractol->z_r) + (fractol->z_i * fractol->z_i)) < 4
		&& fractol->i < fractol->iteration_max)
	{
		fractol->tmp = fractol->z_r;
		fractol->z_r = (fabs(fractol->z_r) * fabs(fractol->z_r)) -
			fabs(fractol->z_i) * fabs(fractol->z_i) + fractol->c_r;
		fractol->z_i = 2 * fabs(fractol->z_i) *
			fabs(fractol->tmp) + fractol->c_i;
		fractol->i++;
	}
}

void	ft_calc_burning(t_fractol *fractol, t_env *e)
{
	while (fractol->y < HEIGHT)
	{
		while (fractol->x < WIDTH)
		{
			fractol->z_r = 0;
			fractol->z_i = 0;
			fractol->c_r = (fractol->x - (WIDTH / 2))
				/ fractol->zoom + fractol->x1;
			fractol->c_i = (fractol->y - (HEIGHT / 2))
				/ fractol->zoom + fractol->y1;
			fractol->i = 0;
			burning_loop(fractol);
			if (fractol->i == fractol->iteration_max)
				e = ft_put_to_image(e, fractol);
			else
				e = ft_put_blue_image(e, fractol);
			fractol->x++;
		}
		fractol->x = 0;
		fractol->y++;
	}
}

void	ft_burning_ship(void *mlx, void *win, t_env *e, t_fractol *fractol)
{
	mlx_clear_window(e->mlx, e->win);
	ft_bzero(e->im, e->size * HEIGHT);
	ft_calc_burning(fractol, e);
	mlx_put_image_to_window(mlx, win, e->ptri, 0, 0);
	fractol->x = 0;
	fractol->y = 0;
	fractol->z_r = 0;
	fractol->z_i = 0;
}
