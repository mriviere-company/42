/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:36:40 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/06 10:26:52 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	size;

	size = ft_strlen(s1) + 1;
	if ((new = malloc(size)) == NULL)
		return (NULL);
	return (ft_memcpy(new, s1, size));
}
