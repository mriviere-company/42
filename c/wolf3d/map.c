/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/24 16:29:13 by mriviere          #+#    #+#             */
/*   Updated: 2016/10/24 16:29:18 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_raycasting(t_env *e)
{
	int x;

	x = -1;
	ft_bzero(e->im, WIDTH * HEIGHT * 4);
	while (++x < WIDTH)
	{
		e->camerax = 2.0 * x / (double)WIDTH - 1.0;
		e->rayposx = e->posx;
		e->rayposy = e->posy;
		e->raydirx = (e->dirx + e->planex * e->camerax);
		e->raydiry = (e->diry + e->planey * e->camerax);
		e->mapx = (int)e->rayposx;
		e->mapy = (int)e->rayposy;
		e->deltadistx = sqrt(1.0 + (e->raydiry * e->raydiry)
			/ (e->raydirx * e->raydirx));
		e->deltadisty = sqrt(1.0 + (e->raydirx * e->raydirx)
			/ (e->raydiry * e->raydiry));
		e->hit = 0;
		ft_init_sidedist(e);
		ft_dda(e);
		ft_calc_raycasting(e);
		ft_put_to_image(e, e->drawstart, e->drawend, x);
	}
	if (e->stamina < e->staminamax)
		e->stamina += 0.3;
}

void	ft_init_sidedist(t_env *e)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1.0;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1.0;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1.0;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1.0;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}

void	ft_dda(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += (int)e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += (int)e->stepy;
			e->side = 1.0;
		}
		if (e->map[e->mapx][e->mapy] != '0' && e->map[e->mapx][e->mapy] != 'X')
			e->hit = 1.0;
	}
}

void	ft_calc_raycasting(t_env *e)
{
	if (e->side == 0)
		e->perpwalldist = (e->mapx - e->rayposx +
		(1.0 - e->stepx) / 2.0) / e->raydirx;
	else
		e->perpwalldist = (e->mapy - e->rayposy +
		(1.0 - e->stepy) / 2.0) / e->raydiry;
	e->lineheight = (int)(HEIGHT / e->perpwalldist);
	e->drawstart = -e->lineheight / 2.0 + HEIGHT / 2.0;
	if (e->drawstart < 0)
		e->drawstart = 0.0;
	if (e->drawstart > HEIGHT)
		e->drawstart = HEIGHT - 1.0;
	e->drawend = e->lineheight / 2.0 + HEIGHT / 2.0;
	if (e->drawend < 0)
		e->drawend = 0.0;
	if (e->drawend > HEIGHT)
		e->drawend = HEIGHT - 1.0;
}

int		texture(t_env *e)
{
	char		**path;
	t_text		*tex;
	int			a;
	void		*ptr;

	a = 0;
	tex = malloc(sizeof(t_text) * 1000000);
	if (!tex)
		return (0);
	path = ft_strsplit("./img/m.xpm ./img/m2.xpm ./img/t.xpm ./img/p.xpm", ' ');
	while (path[a])
	{
		ptr = mlx_xpm_file_to_image(e->mlx, path[a],
			&tex[a].width, &tex[a].height);
		if (!ptr)
			return (0);
		tex[a].im = mlx_get_data_addr(ptr, &tex[a].bpp,
			&tex[a].size, &tex[a].endian);
		free(path[a]);
		a++;
	}
	free(path);
	e->text = tex;
	free(tex);
	return (42);
}
