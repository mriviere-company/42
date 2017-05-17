/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:20:41 by mriviere          #+#    #+#             */
/*   Updated: 2014/12/03 14:20:54 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int nombre)
{
	int	counter;

	counter = 0;
	if (nombre == 0)
		return (1);
	while (nombre > 0)
	{
		nombre = nombre / 10;
		counter++;
	}
	return (counter);
}
