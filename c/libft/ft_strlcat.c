/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:49:49 by mriviere          #+#    #+#             */
/*   Updated: 2015/01/04 14:38:01 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	s1;
	unsigned int	s2;
	unsigned int	i;

	s1 = ft_strlen(dst);
	s2 = ft_strlen(src);
	i = 0;
	if (size <= s1)
		return (s2 + size);
	while (s1 + i < size - 1)
	{
		dst[s1 + i] = src[i];
		i++;
	}
	dst[s1 + i] = '\0';
	return (s1 + s2);
}
