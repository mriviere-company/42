/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:40:49 by mriviere          #+#    #+#             */
/*   Updated: 2016/10/24 16:40:50 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_rotate_camera2(t_env *e)
{
	double rotspeed;

	rotspeed = 0.05f;
	e->olddirx = e->dirx;
	e->dirx = e->dirx * cos(rotspeed) - e->diry * sin(rotspeed);
	e->diry = e->olddirx * sin(rotspeed) + e->diry * cos(rotspeed);
	e->oldplanex = e->planex;
	e->planex = e->planex * cos(rotspeed) - e->planey * sin(rotspeed);
	e->planey = e->oldplanex * sin(rotspeed) + e->planey * cos(rotspeed);
}

void		ft_rotate_camera(t_env *e)
{
	double rotspeed;

	rotspeed = 0.05f;
	e->olddirx = e->dirx;
	e->dirx = e->dirx * cos(-rotspeed) - e->diry * sin(-rotspeed);
	e->diry = e->olddirx * sin(-rotspeed) + e->diry * cos(-rotspeed);
	e->oldplanex = e->planex;
	e->planex = e->planex * cos(-rotspeed) - e->planey * sin(-rotspeed);
	e->planey = e->oldplanex * sin(-rotspeed) + e->planey * cos(-rotspeed);
}

void		ft_norm(t_env *e, int x, int y)
{
	e->im[(int)(x * 4 + y * e->size) + 1] = 150.0f *
	((float)e->stamina / e->staminamax);
	e->im[(int)(x * 4 + y * e->size) + 2] = 194;
}

void		ft_draw_stamina(t_env *e)
{
	int		x;
	int		y;
	float	i;

	e->stam = 0;
	while (e->stam < 15)
	{
		y = e->stam + 300;
		i = 0.0;
		x = 100;
		while (i < 150)
		{
			e->im[(int)(x * 4 + y * e->size)] = 0;
			e->im[(int)(x * 4 + y * e->size) + 1] = 0;
			e->im[(int)(x * 4 + y * e->size) + 2] = 0;
			if (e->stam < 4 || e->stam > 10 || i < 6 || i > e->stamina /
				(100.0f / 150.0f) || i > 144)
				e->im[(int)(x * 4 + y * e->size) + 0] = 100;
			else
				ft_norm(e, x, y);
			i += 1;
			x++;
		}
		e->stam++;
	}
}
