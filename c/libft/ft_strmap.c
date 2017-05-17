/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:46:36 by mriviere          #+#    #+#             */
/*   Updated: 2014/11/07 10:51:18 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		c;
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	c = ft_strlen(s);
	str = ft_strnew(c);
	i = 0;
	while (i < c)
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
