/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:53:08 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/07 10:56:35 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	c;
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	c = ft_strlen(s);
	str = ft_strnew(c);
	i = 0;
	while (i < c)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
