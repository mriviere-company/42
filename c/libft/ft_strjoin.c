/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:19:04 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/07 11:21:39 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	char	*tmpc;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	c = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (c == NULL)
		return (NULL);
	tmpc = c;
	while (*s1 != '\0')
		*tmpc++ = *s1++;
	while (*s2 != '\0')
		*tmpc++ = *s2++;
	*tmpc = '\0';
	return (c);
}
