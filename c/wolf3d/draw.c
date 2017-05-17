/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 18:27:59 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/03 18:28:04 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_draw_wall1(t_env *e, int y, int end, int x)
{
	while (y < end)
	{
		e->im[(int)(x * 4 + y * e->size)] = 0;
		e->im[(int)(x * 4 + y * e->size) + 1] = 0;
		e->im[(int)(x * 4 + y * e->size) + 2] = 255;
		y++;
	}
	return (y);
}

int			ft_draw_wall2(t_env *e, int y, int end, int x)
{
	while (y < end)
	{
		e->im[(int)(x * 4 + y * e->size)] = 0;
		e->im[(int)(x * 4 + y * e->size) + 1] = 255;
		e->im[(int)(x * 4 + y * e->size) + 2] = 0;
		y++;
	}
	return (y);
}

int			ft_draw_wall3(t_env *e, int y, int end, int x)
{
	while (y < end)
	{
		e->im[(int)(x * 4 + y * e->size)] = 255;
		e->im[(int)(x * 4 + y * e->size) + 1] = 0;
		e->im[(int)(x * 4 + y * e->size) + 2] = 0;
		y++;
	}
	return (y);
}

int			ft_draw_wall4(t_env *e, int y, int end, int x)
{
	while (y < end)
	{
		e->im[(int)(x * 4 + y * e->size)] = 54;
		e->im[(int)(x * 4 + y * e->size) + 1] = 255;
		e->im[(int)(x * 4 + y * e->size) + 2] = 255;
		y++;
	}
	return (y);
}
