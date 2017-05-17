/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:05:27 by mriviere          #+#    #+#             */
/*   Updated: 2016/10/20 16:06:24 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

void	ft_put_in_tab(char *argument, t_env *e)
{
	char	*buffer;
	int		fd;
	int		i;

	i = 0;
	if (open(argument, O_DIRECTORY) > 0)
		ft_error("Argument isn't Correct !", argument);
	fd = open(argument, O_RDONLY);
	while (get_next_line(fd, &buffer) == 1)
		i++;
	close(fd);
	ft_parse(argument, i, e);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 && e->point.zoom < 40)
		e->point.zoom += PI / 20;
	if (keycode == 1 && e->point.zoom > 1)
		e->point.zoom -= PI / 20;
	if (keycode == 2)
		e->point.inc -= 1;
	if (keycode == 14)
		e->point.inc += 1;
	if (keycode == 126)
		e->point.degx += PI / 100;
	if (keycode == 125)
		e->point.degx -= PI / 100;
	if (keycode == 124)
		e->point.degy += PI / 100;
	if (keycode == 123)
		e->point.degy -= PI / 100;
	expose_hook(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
		ft_error("Must have one map and only one !", "");
	e.point.degx = (0.8);
	e.point.degy = (0.8);
	e.point.h = 1200;
	e.point.w = 1200;
	e.point.zoom = 20;
	e.point.inc = 0;
	ft_put_in_tab(argv[1], &e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.point.h, e.point.w, "fdf");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, 2, 1, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
