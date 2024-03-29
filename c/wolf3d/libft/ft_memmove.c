/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:33:47 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/08 18:11:31 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char*)dst;
	s = (char*)src;
	if (d < s)
		return (ft_memcpy(dst, src, len));
	while (len--)
	{
		d[len] = s[len];
	}
	return (dst);
}
