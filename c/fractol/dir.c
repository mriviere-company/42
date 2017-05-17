/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:42:43 by mriviere          #+#    #+#             */
/*   Updated: 2016/05/31 10:52:50 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_up(t_env *e)
{
	e->fractal->y1 += 50 * (PI / 10) / e->fractal->zoom;
	expose_hook(e);
}

void	ft_down(t_env *e)
{
	e->fractal->y1 -= 50 * (PI / 10) / e->fractal->zoom;
	expose_hook(e);
}

void	ft_left(t_env *e)
{
	e->fractal->x1 += 50 * (PI / 10) / e->fractal->zoom;
	expose_hook(e);
}

void	ft_right(t_env *e)
{
	e->fractal->x1 -= 50 * (PI / 10) / e->fractal->zoom;
	expose_hook(e);
}
