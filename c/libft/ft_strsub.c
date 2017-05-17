/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:09:22 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/07 11:14:57 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dst;

	if (s == NULL)
		return (NULL);
	dst = ft_strnew(len + 1);
	i = 0;
	if (dst == NULL)
		return (NULL);
	while (i < len + start)
	{
		if (i >= start)
		{
			dst[i - start] = s[i];
		}
		i++;
	}
	return (dst);
}
