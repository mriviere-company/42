/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:14:52 by mriviere          #+#    #+#             */
/*   Updated: 2016/10/20 12:18:51 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham_print(t_point2d a, t_point2d b, t_env *e)
{
	e->point.x_tmp = a.x;
	e->point.y_tmp = a.y;
	e->point.new_x = a.x;
	e->point.new_y = a.y;
	while ((e->point.x_tmp != b.x || e->point.y_tmp != b.y) ||
		(e->point.vecdir_x == 0 && e->point.y_tmp != b.y) ||
		(e->point.vecdir_y == 0 && e->point.x_tmp != b.x))
	{
		if (e->point.x_tmp != b.x)
			e->point.new_x += e->point.vecdir_x;
		if (e->point.y_tmp != b.y)
			e->point.new_y += e->point.vecdir_y;
		if ((int)e->point.new_x != a.x)
			e->point.x_tmp = e->point.new_x;
		if ((int)e->point.new_y != a.y)
			e->point.y_tmp = e->point.new_y;
		if (e->point.x_tmp + e->point.dec < e->point.w && e->point.x_tmp +
			e->point.dec > 0 && e->point.y_tmp + e->point.dec < e->point.h &&
			e->point.y_tmp + e->point.dec > 0)
			ft_go_image(e, e->point.x_tmp + e->point.dec,
			e->point.y_tmp + e->point.dec, e->z);
	}
}

void	ft_bresenham(t_point2d a, t_point2d b, t_env *e)
{
	e->point.vecdir_x = b.x - a.x;
	e->point.vecdir_y = b.y - a.y;
	if (fabs(e->point.vecdir_x) > fabs(e->point.vecdir_y))
	{
		e->point.vecdir_y /= fabs(e->point.vecdir_x);
		e->point.vecdir_x /= fabs(e->point.vecdir_x);
	}
	else
	{
		e->point.vecdir_x /= fabs(e->point.vecdir_y);
		e->point.vecdir_y /= fabs(e->point.vecdir_y);
	}
	ft_bresenham_print(a, b, e);
}

void	ft_next_3d_place(t_point2d a, t_point2d b, t_env *e)
{
	if (e->coord.x + 1 < e->point.mapx)
	{
		e->point.x = (e->coord.x + 1 - (e->point.mapx / 2)) * e->point.zoom;
		e->point.y = (e->coord.y - (e->point.mapy / 2)) * e->point.zoom;
		e->point.z = e->map[e->coord.y][e->coord.x + 1];
		ft_check_z(e);
		e->z = e->point.z;
		e->point = matrice_x(e->point);
		b.x = e->point.x;
		b.y = e->point.y;
		ft_bresenham(a, b, e);
	}
	if (e->coord.y + 1 < e->point.mapy)
	{
		e->point.x = (e->coord.x - (e->point.mapx / 2)) * e->point.zoom;
		e->point.y = (e->coord.y + 1 - (e->point.mapy / 2)) * e->point.zoom;
		e->point.z = e->map[e->coord.y + 1][e->coord.x];
		ft_check_z(e);
		e->z = e->point.z;
		e->point = matrice_x(e->point);
		b.x = e->point.x;
		b.y = e->point.y;
		ft_bresenham(a, b, e);
	}
}

void	ft_3d_place(t_env *e)
{
	t_point2d a;
	t_point2d b;

	e->point.x = (e->coord.x - (e->point.mapx / 2)) * e->point.zoom;
	e->point.y = (e->coord.y - (e->point.mapy / 2)) * e->point.zoom;
	e->point.z = e->map[e->coord.y][e->coord.x];
	ft_check_z(e);
	e->point = matrice_x(e->point);
	a.x = e->point.x;
	a.y = e->point.y;
	b.x = 0;
	b.y = 0;
	ft_next_3d_place(a, b, e);
}

int		draw(t_env *e)
{
	e->coord.x = 0;
	e->coord.y = 0;
	e->point.dec = (e->point.w / 2);
	e->ptri = mlx_new_image(e->mlx, e->point.h, e->point.w);
	e->im = mlx_get_data_addr(e->ptri, &e->bpp, &e->size, &e->endian);
	while (e->coord.y < e->point.mapy)
	{
		while (e->coord.x < e->point.mapx)
		{
			ft_3d_place(e);
			e->coord.x++;
		}
		e->coord.x = 0;
		e->coord.y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->ptri, 0, 0);
	return (0);
}
