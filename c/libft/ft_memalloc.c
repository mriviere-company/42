/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:13:33 by mriviere          #+#    #+#             */
/*   Updated: 2015/01/04 15:09:59 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned	int	c;
	char			*pl;

	if (size == 0)
		return (0);
	c = 0;
	mem = (void *)malloc(size);
	pl = (char *)mem;
	if (mem != NULL)
	{
		while (c++ < size)
			*pl++ = 0;
	}
	return (pl);
}
