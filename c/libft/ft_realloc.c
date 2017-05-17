/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 14:49:51 by mriviere          #+#    #+#             */
/*   Updated: 2014/12/01 12:27:27 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*plus;

	plus = ft_memalloc(size);
	if (ptr)
	{
		if (plus)
			ft_memcpy(plus, ptr, size);
		ft_memdel(&ptr);
	}
	return (plus);
}
