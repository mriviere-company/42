/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 17:19:41 by mriviere          #+#    #+#             */
/*   Updated: 2016/05/04 17:20:42 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_crosshair2(t_env *e, int i, int y, int x)
{
	y = HEIGHT / 2;
	x += 5;
	while (i != 30)
	{
		e->im[(int)(x * 4 + y * e->size)] = 0;
		e->im[(int)(x * 4 + y * e->size) + 1] = 255;
		e->im[(int)(x * 4 + y * e->size) + 2] = 0;
		x++;
		i++;
	}
	x -= 20;
	while (i != 40)
	{
		e->im[(int)(x * 4 + y * e->size)] = 0;
		e->im[(int)(x * 4 + y * e->size) + 1] = 255;
		e->im[(int)(x * 4 + y * e->size) + 2] = 0;
		x--;
		i++;
	}
	ft_draw_stamina(e);
}

void		ft_crosshair(t_env *e)
{
	int x;
	int y;
	int i;

	y = (HEIGHT / 2) + 5;
	x = WIDTH / 2;
	i = 0;
	while (i != 10)
	{
		e->im[(int)(x * 4 + y * e->size)] = 0;
		e->im[(int)(x * 4 + y * e->size) + 1] = 255;
		e->im[(int)(x * 4 + y * e->size) + 2] = 0;
		y++;
		i++;
	}
	y -= 20;
	while (i != 20)
	{
		e->im[(int)(x * 4 + y * e->size)] = 0;
		e->im[(int)(x * 4 + y * e->size) + 1] = 255;
		e->im[(int)(x * 4 + y * e->size) + 2] = 0;
		y--;
		i++;
	}
	ft_crosshair2(e, i, y, x);
}

void		ft_error(char *error, char *str)
{
	ft_putstr("Error : ");
	ft_putendl(str);
	ft_putendl(error);
	exit(0);
}
