/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:17:19 by mriviere          #+#    #+#             */
/*   Updated: 2016/05/04 17:17:21 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		rotation_y(t_point l)
{
	double x;
	double y;
	double z;
	double un;

	x = l.x * l.a1 + l.y * l.a2 + l.z * l.a3 + l.un * l.a4;
	y = l.x * l.b1 + l.y * l.b2 + l.z * l.b3 + l.un * l.b4;
	z = l.x * l.c1 + l.y * l.c2 + l.z * l.c3 + l.un * l.c4;
	un = l.x * l.d1 + l.y * l.d2 + l.z * l.d3 + l.un * l.d4;
	l.x = x;
	l.y = y;
	l.z = z;
	l.un = un;
	return (l);
}

t_point		matrice_y(t_point list)
{
	list.a1 = cos(list.degy);
	list.a2 = 0;
	list.a3 = sin(list.degy);
	list.a4 = 0;
	list.b1 = 0;
	list.b2 = 1;
	list.b3 = 0;
	list.b4 = 0;
	list.c1 = -sin(list.degy);
	list.c2 = 0;
	list.c3 = cos(list.degy);
	list.c4 = 0;
	list.d1 = 0;
	list.d2 = 0;
	list.d3 = 0;
	list.d4 = 1;
	list = rotation_y(list);
	return (list);
}

t_point		rotation_x(t_point l)
{
	double x;
	double y;
	double z;
	double un;

	x = l.x * l.a1 + l.y * l.a2 + l.z * l.a3 + l.un * l.a4;
	y = l.x * l.b1 + l.y * l.b2 + l.z * l.b3 + l.un * l.b4;
	z = l.x * l.c1 + l.y * l.c2 + l.z * l.c3 + l.un * l.c4;
	un = l.x * l.d1 + l.y * l.d2 + l.z * l.d3 + l.un * l.d4;
	l.x = x;
	l.y = y;
	l.z = z;
	l.un = un;
	l = matrice_y(l);
	return (l);
}

t_point		matrice_x(t_point list)
{
	list.a1 = 1;
	list.a2 = 0;
	list.a3 = 0;
	list.a4 = 0;
	list.b1 = 0;
	list.b2 = cos(list.degx);
	list.b3 = -sin(list.degx);
	list.b4 = 0;
	list.c1 = 0;
	list.c2 = sin(list.degx);
	list.c3 = cos(list.degx);
	list.c4 = 0;
	list.d1 = 0;
	list.d2 = 0;
	list.d3 = 0;
	list.d4 = 1;
	list = rotation_x(list);
	return (list);
}
