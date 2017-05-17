/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:29:28 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/16 11:16:05 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*ptr2;
	const char		*ptr1;

	ptr1 = (char*)src;
	ptr2 = (char*)dst;
	while (n--)
	{
		if (*ptr1 == c)
		{
			*ptr2++ = *ptr1++;
			return (ptr2);
		}
		*ptr2++ = *ptr1++;
	}
	return (NULL);
}
