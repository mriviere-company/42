/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:15:11 by mriviere          #+#    #+#             */
/*   Updated: 2016/10/20 22:12:05 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_add_int(int t, char *buffer, t_env *e)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(buffer, ' ');
	while (tmp[i])
	{
		e->map[t][i] = ft_atoi(tmp[i]);
		i++;
	}
}

int		ft_nb_space(char *buffer)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] != ' ')
		{
			while (buffer[i] && buffer[i] != ' ')
				i++;
			j++;
		}
		i++;
	}
	return (j);
}

void	ft_parse(char *argument, int i, t_env *e)
{
	char	*buffer;
	int		fd;
	int		j;
	int		space;

	fd = open(argument, O_RDONLY);
	e->map = (int **)malloc(sizeof(int*) * i + 1);
	i = 0;
	j = 0;
	while (get_next_line(fd, &buffer) == 1)
	{
		if ((space = ft_nb_space(buffer)) > e->point.mapx)
			e->point.mapx = space;
		else if (space != e->point.mapx)
			ft_error("Each lines must have equal number of value !", "");
		e->map[i] = (int*)malloc(sizeof(int) * e->point.mapx + 1);
		ft_add_int(i, buffer, e);
		i++;
	}
	e->point.mapy = i;
	close(fd);
}
