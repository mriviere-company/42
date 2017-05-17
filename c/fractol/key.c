/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:25:41 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 18:41:33 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_env *e)
{
	if (e->fractal->zoom <= 0)
		e->fractal->zoom = 2;
	else
		e->fractal->zoom *= 1.5;
	expose_hook(e);
}

void	unzoom(t_env *e)
{
	if (e->fractal->zoom <= 0)
		return ;
	e->fractal->zoom /= 1.5;
	expose_hook(e);
}

int		key_hook2(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		e->fractal->iteration_max += 25;
		expose_hook(e);
	}
	else if (keycode == 78)
	{
		if (e->fractal->iteration_max > 50)
		{
			e->fractal->iteration_max -= 25;
			expose_hook(e);
		}
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 125)
		ft_up(e);
	else if (keycode == 124)
		ft_left(e);
	else if (keycode == 123)
		ft_right(e);
	else if (keycode == 126)
		ft_down(e);
	else if (keycode == 116)
		zoom(e);
	else if (keycode == 121)
		unzoom(e);
	else
		key_hook2(keycode, e);
	return (0);
}
