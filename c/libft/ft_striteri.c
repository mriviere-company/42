/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:40:32 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/07 10:41:58 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	c;
	int	i;

	if (s != NULL && f != NULL)
	{
		c = ft_strlen(s);
		i = 0;
		while (i < c)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
