/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:19:41 by mriviere          #+#    #+#             */
/*   Updated: 2016/10/20 22:10:31 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env		*ft_go_image_next(t_env *e, int x, int y, int color)
{
	if (color < 80)
	{
		e->im[(int)(x * 4 + y * e->size)] = 0;
		e->im[(int)(x * 4 + y * e->size) + 1] = 51;
		e->im[(int)(x * 4 + y * e->size) + 2] = 102;
	}
	else
	{
		e->im[(int)(x * 4 + y * e->size)] = 255;
		e->im[(int)(x * 4 + y * e->size) + 1] = 255;
		e->im[(int)(x * 4 + y * e->size) + 2] = 255;
	}
	return (e);
}

t_env		*ft_go_image(t_env *e, int x, int y, int color)
{
	if (color <= 0)
	{
		e->im[(int)(x * 4 + y * e->size)] = 255;
		e->im[(int)(x * 4 + y * e->size) + 1] = 0;
		e->im[(int)(x * 4 + y * e->size) + 2] = 0;
	}
	else if (color < 15)
	{
		e->im[(int)(x * 4 + y * e->size)] = 102;
		e->im[(int)(x * 4 + y * e->size) + 1] = 204;
		e->im[(int)(x * 4 + y * e->size) + 2] = 255;
	}
	else if (color < 60)
	{
		e->im[(int)(x * 4 + y * e->size)] = 0;
		e->im[(int)(x * 4 + y * e->size) + 1] = 153;
		e->im[(int)(x * 4 + y * e->size) + 2] = 0;
	}
	else
		ft_go_image_next(e, x, y, color);
	return (e);
}

void		ft_check_z(t_env *e)
{
	if (e->point.z > 0)
		e->point.z += e->point.inc;
}

void		ft_error(char *error, char *str)
{
	ft_putstr("Error : ");
	ft_putendl(str);
	ft_putendl(error);
	exit(0);
}
