/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:02:33 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 18:21:13 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse(const int b, int x, int y, t_env *e)
{
	if ((b == 5 || b == 1))
	{
		e->fractal->x1 += (x - (WIDTH / 2)) * (1.0 / e->fractal->zoom);
		e->fractal->y1 += (y - (HEIGHT / 2)) * (1.0 / e->fractal->zoom);
		e->fractal->zoom *= 1.1;
	}
	else if (b == 4 || b == 2)
		e->fractal->zoom /= 1.1;
	draw(e->mlx, e->win, e);
	return (0);
}

int		mouse_hook(int x, int y, t_env *e)
{
	if (e->i == 1)
	{
		e->x = x;
		e->y = y;
		expose_hook(e);
	}
	return (0);
}
