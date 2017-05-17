/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 10:39:59 by mriviere          #+#    #+#             */
/*   Updated: 2016/02/03 10:37:10 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_whereareyou(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

static char		*ft_joinmeboy(char *s1, char *s2)
{
	char		*ret;
	char		*tmp;
	int			len;

	tmp = s1;
	while (*tmp != '\0')
		tmp++;
	ret = s2;
	while (*ret != '\0')
		ret++;
	len = ret - s2;
	if ((ret = (char *)malloc(sizeof(char) * (1 + len + tmp - s1))) == NULL)
		return (NULL);
	ret[len + (tmp - s1)] = '\0';
	tmp = ret;
	while ((*tmp = *(s1++)) != '\0')
		tmp++;
	while ((*tmp = *(s2++)) != '\0')
		tmp++;
	return (ret);
}

static int		areyouthelast(char **line, char **buf)
{
	if (**buf != '\0')
	{
		*line = *buf;
		*buf = NULL;
		return (1);
	}
	return (0);
}

static int		lineincoming(int fd, char **line, char **buf)
{
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	while ((ret = read(fd, buffer, BUFF_SIZE)) != '\0')
	{
		buffer[ret] = '\0';
		if (ret == -1)
			return (-1);
		if ((tmp = ft_whereareyou(buffer)) != '\0')
		{
			*tmp = '\0';
			if ((*line = ft_joinmeboy(*buf, buffer)) == NULL
				|| (tmp = ft_joinmeboy(tmp + 1, "\0")) == NULL)
				return (-1);
			free(*buf);
			*buf = tmp;
			return (1);
		}
		if ((tmp = ft_joinmeboy(*buf, buffer)) == NULL)
			return (-1);
		free(*buf);
		*buf = tmp;
	}
	return (areyouthelast(line, buf));
}

int				get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (buf != '\0')
	{
		if ((tmp = ft_whereareyou(buf)) != '\0')
		{
			*tmp = '\0';
			if ((*line = ft_joinmeboy(buf, "\0")) == NULL
				|| (tmp = ft_joinmeboy(tmp + 1, "\0")) == NULL)
				return (-1);
			free(buf);
			buf = tmp;
			return (1);
		}
	}
	else
	{
		if ((buf = (char *)malloc(sizeof(char))) == NULL)
			return (-1);
		*buf = '\0';
	}
	return (lineincoming(fd, line, &buf));
}
