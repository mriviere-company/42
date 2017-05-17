/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/28 17:06:02 by mriviere          #+#    #+#             */
/*   Updated: 2016/06/28 17:06:07 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_find_wall(t_env *e)
{
	int i;

	if (e->map[e->mapx][e->mapy] == '1')
		i = 0;
	if (e->map[e->mapx][e->mapy] == '2')
		i = 1;
	if (e->map[e->mapx][e->mapy] == 'T' || e->map[e->mapx][e->mapy] == 'D')
		i = 2;
	if (e->map[e->mapx][e->mapy] == 'P')
		i = 3;
	return (i);
}

int			ft_print_texture(t_env *e, int y, int x, int end)
{
	int d;

	while (y < end)
	{
		d = y * 256 - HEIGHT * 128 + e->lineheight * 128;
		e->text[e->t].y = ((d * e->text->height) / e->lineheight) / 256;
		if (d > 0 && e->text[e->t].y > 0)
		{
			e->im[(int)(x * 4 + y * e->size)] = e->text[e->t].im[e->text
			[e->t].x * 4 + e->text[e->t].y * e->text[e->t].size];
			e->im[(int)(x * 4 + y * e->size) + 1] = e->text[e->t].im[(e->
			text[e->t].x * 4 + e->text[e->t].y * e->text[e->t].size) + 1];
			e->im[(int)(x * 4 + y * e->size) + 2] = e->text[e->t].im[(e->
			text[e->t].x * 4 + e->text[e->t].y * e->text[e->t].size) + 2];
		}
		y++;
	}
	return (y);
}

int			ft_texture(t_env *e, int y, int end, int x)
{
	double wallx;

	e->t = ft_find_wall(e);
	if (e->side == 0)
		wallx = e->rayposy + e->perpwalldist * e->raydiry;
	else
		wallx = e->rayposx + e->perpwalldist * e->raydirx;
	wallx -= (int)wallx;
	e->text[e->t].x = (int)(wallx * (double)e->text[e->t].width);
	if (e->side == 0 && e->raydirx > 0)
		e->text[e->t].x = e->text[e->t].width - e->text[e->t].x - 1;
	if (e->side == 1 && e->raydiry < 0)
		e->text[e->t].x = e->text[e->t].width - e->text[e->t].x - 1;
	y = ft_print_texture(e, y, x, end);
	return (y);
}

void		ft_draw_sky_floor(t_env *e, int y, int x, int tmp_y)
{
	int tmp;

	tmp = 0;
	while (tmp <= tmp_y)
	{
		e->im[(int)(x * 4 + tmp_y * e->size)] = 64;
		e->im[(int)(x * 4 + tmp_y * e->size) + 1] = 64;
		e->im[(int)(x * 4 + tmp_y * e->size) + 2] = 64;
		tmp_y--;
	}
	while (y < HEIGHT)
	{
		e->im[(int)(x * 4 + y * e->size)] = 64;
		e->im[(int)(x * 4 + y * e->size) + 1] = 64;
		e->im[(int)(x * 4 + y * e->size) + 2] = 64;
		y++;
	}
}

t_env		*ft_put_to_image(t_env *e, int y, int end, int x)
{
	int tmp;
	int tmp_y;

	tmp_y = y;
	tmp = 0;
	if (e->secure == 42)
		y = ft_texture(e, y, end, x);
	else
	{
		if (e->side == 0 && e->stepx == 1)
			y = ft_draw_wall1(e, y, end, x);
		else if (e->side == 1 && e->stepy == 1)
			y = ft_draw_wall2(e, y, end, x);
		else if (e->side == 0)
			y = ft_draw_wall3(e, y, end, x);
		else if (e->side == 1)
			y = ft_draw_wall4(e, y, end, x);
	}
	ft_draw_sky_floor(e, y, x, tmp_y);
	ft_crosshair(e);
	return (e);
}
