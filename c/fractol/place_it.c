/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:18:15 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 18:02:42 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		rainbow(t_fractol *fractol, t_env *e)
{
	double	c;
	int		red;
	int		green;
	int		blue;

	if (fractol->i == fractol->iteration_max)
		return (0);
	c = e->frequency * (fractol->i + 1);
	red = cos(c) * 127 + 160;
	green = cos(c + e->color) * 127 + 160;
	blue = cos(c + e->color + e->color) * 127 + 160;
	return ((red << 16) + (blue << 8) + green);
}

t_env	*ft_put_blue_image(t_env *e, t_fractol *fractol)
{
	int color;

	color = rainbow(fractol, e);
	e->im[((int)fractol->x * (e->bpp / 8)) +
	(int)fractol->y * e->size] = color;
	color >>= 8;
	e->im[((int)fractol->x * (e->bpp / 8) +
	(int)fractol->y * e->size) + 1] = color;
	color >>= 8;
	e->im[((int)fractol->x * (e->bpp / 8) +
	(int)fractol->y * e->size) + 2] = color;
	return (e);
}

t_env	*ft_put_to_image(t_env *e, t_fractol *fractol)
{
	int color;

	color = rainbow(fractol, e);
	e->im[((int)fractol->x * (e->bpp / 8)) + (int)fractol->y
			* e->size] = (fractol->i % 106)
			* (fractol->i < fractol->iteration_max);
	color >>= 8;
	e->im[((int)fractol->x * (e->bpp / 8) + (int)fractol->y
			* e->size) + 1] = (fractol->i % 106)
			* (fractol->i < fractol->iteration_max);
	color >>= 8;
	e->im[((int)fractol->x * (e->bpp / 8) + (int)fractol->y
			* e->size) + 2] = (fractol->i % 106)
			* (fractol->i < fractol->iteration_max);
	return (e);
}
