/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:58:51 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/10 11:50:52 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;
	int			i;

	s1 = (char*)dst;
	s2 = (const char*)src;
	i = 0;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	s2 = s2 + len;
	s1 = s1 + len;
	while (len--)
	{
		i--;
		*(s1 + i) = *(s2 + i);
	}
	return (dst);
}
