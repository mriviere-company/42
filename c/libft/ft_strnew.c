/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 09:53:44 by mriviere          #+#    #+#             */
/*   Updated: 2015/01/04 14:41:55 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return ((char *)NULL);
	else
		ft_bzero(s, size + 1);
	return (s);
}
