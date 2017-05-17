/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:32:28 by mriviere          #+#    #+#             */
/*   Updated: 2016/10/24 16:32:30 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf3d");
	e->ptri = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->im = mlx_get_data_addr(e->ptri, &e->bpp, &e->size, &e->endian);
	if (texture(e) != 42)
		ft_putendl("Restart the game");
}

void	ft_init_render(t_env *e)
{
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 1, key_hook, e);
	mlx_loop_hook(e->mlx, uptade, e);
	mlx_loop(e->mlx);
}

void	ft_init_env(t_env *e)
{
	e->posx = 10;
	e->posy = 10;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
}
