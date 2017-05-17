/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/28 16:50:49 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/28 16:50:50 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_move_forward(t_env *e, double movespeed)
{
	if (e->map[(int)(e->posx + e->dirx * movespeed * 2)][(int)e->posy] == '0' ||
		e->map[(int)(e->posx + e->dirx * movespeed * 2)][(int)e->posy] == 'T' ||
		e->map[(int)(e->posx + e->dirx * movespeed * 2)][(int)e->posy] == 'D' ||
		e->map[(int)(e->posx + e->dirx * movespeed * 2)][(int)e->posy] == 'X')
		e->posx += e->dirx * movespeed;
	if (e->map[(int)e->posx][(int)(e->posy + e->diry * movespeed * 2)] == '0' ||
		e->map[(int)e->posx][(int)(e->posy + e->diry * movespeed * 2)] == 'T' ||
		e->map[(int)e->posx][(int)(e->posy + e->diry * movespeed * 2)] == 'D' ||
		e->map[(int)e->posx][(int)(e->posy + e->diry * movespeed * 2)] == 'X')
		e->posy += e->diry * movespeed;
	if (e->map[(int)e->posx][(int)e->posy] == 'T')
	{
		e->posx = 17;
		e->posy = 3;
	}
	if (e->map[(int)e->posx][(int)e->posy] == 'D')
	{
		e->posx = 10;
		e->posy = 10;
	}
}

void	ft_move_back(t_env *e, double movespeed)
{
	if (e->map[(int)(e->posx - e->dirx * movespeed * 2)][(int)e->posy] == '0' ||
		e->map[(int)(e->posx - e->dirx * movespeed * 2)][(int)e->posy] == 'T' ||
		e->map[(int)(e->posx - e->dirx * movespeed * 2)][(int)e->posy] == 'D' ||
		e->map[(int)(e->posx - e->dirx * movespeed * 2)][(int)e->posy] == 'X')
		e->posx -= e->dirx * movespeed;
	if (e->map[(int)e->posx][(int)(e->posy - e->diry * movespeed * 2)] == '0' ||
		e->map[(int)e->posx][(int)(e->posy - e->diry * movespeed * 2)] == 'T' ||
		e->map[(int)e->posx][(int)(e->posy - e->diry * movespeed * 2)] == 'D' ||
		e->map[(int)e->posx][(int)(e->posy - e->diry * movespeed * 2)] == 'X')
		e->posy -= e->diry * movespeed;
	if (e->map[(int)e->posx][(int)e->posy] == 'T')
	{
		e->posx = 2;
		e->posy = 3;
	}
	if (e->map[(int)e->posx][(int)e->posy] == 'D')
	{
		e->posx = 10;
		e->posy = 21;
	}
}

void	ft_door(t_env *e)
{
	if (e->map[(int)e->posx + 1][(int)e->posy] == 'P')
		e->map[(int)e->posx + 1][(int)e->posy] = 'X';
	else if (e->map[(int)e->posx][(int)e->posy + 1] == 'P')
		e->map[(int)e->posx][(int)e->posy + 1] = 'X';
	else if (e->map[(int)e->posx - 1][(int)e->posy] == 'P')
		e->map[(int)e->posx - 1][(int)e->posy] = 'X';
	else if (e->map[(int)e->posx][(int)e->posy - 1] == 'P')
		e->map[(int)e->posx][(int)e->posy - 1] = 'X';
	else if (e->map[(int)e->posx + 1][(int)e->posy] == 'X')
		e->map[(int)e->posx + 1][(int)e->posy] = 'P';
	else if (e->map[(int)e->posx][(int)e->posy + 1] == 'X')
		e->map[(int)e->posx][(int)e->posy + 1] = 'P';
	else if (e->map[(int)e->posx - 1][(int)e->posy] == 'X')
		e->map[(int)e->posx - 1][(int)e->posy] = 'P';
	else if (e->map[(int)e->posx][(int)e->posy - 1] == 'X')
		e->map[(int)e->posx][(int)e->posy - 1] = 'P';
}

void	key_stam(t_env *e, double movespeed)
{
	if (e->stamina > 0.0)
	{
		ft_move_forward(e, 0.0045 * 60);
		e->stamina -= 2.5;
	}
	else
		ft_move_forward(e, movespeed);
}

int		key_hook(int keycode, t_env *e)
{
	double movespeed;

	movespeed = 0.0045 * 30;
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		ft_move_forward(e, movespeed);
	if (keycode == 125)
		ft_move_back(e, movespeed);
	if (keycode == 124)
		ft_rotate_camera(e);
	if (keycode == 123)
		ft_rotate_camera2(e);
	if (keycode == 119)
		key_stam(e, movespeed);
	if (keycode == 2)
	{
		if (e->secure == 0)
			e->secure = 42;
		else
			e->secure = 0;
	}
	if (keycode == 36)
		ft_door(e);
	return (0);
}
