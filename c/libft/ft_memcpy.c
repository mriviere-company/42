/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:54:54 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/10 11:46:45 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	i = 0;
	s1 = (char*)dst;
	s2 = (char*)src;
	while (i < n)
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	return (dst);
}
