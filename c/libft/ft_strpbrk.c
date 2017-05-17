/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 18:16:17 by mriviere          #+#    #+#             */
/*   Updated: 2014/12/01 12:30:27 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strpbrk(const char *s1, const char *s2)
{
	if (s1)
		while (*s1)
		{
			if (ft_strchr(s2, *s1))
				return ((char*)s1);
			s1++;
		}
	return (NULL);
}
