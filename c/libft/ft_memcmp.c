/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:26:43 by mriviere          #+#    #+#             */
/*   Updated: 2015/01/04 13:49:11 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ps1;
	unsigned char		*ps2;
	unsigned int		i;
	int					t;
	int					r;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	i = 0;
	t = 0;
	r = 0;
	while (i < n && !t)
	{
		r = r + (ps1[i] - ps2[i]);
		if (ps2[i] != ps1[i])
			t = 1;
		i++;
	}
	return (r);
}
