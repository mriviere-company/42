/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriviere <mriviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:17:09 by mriviere          #+#    #+#             */
/*   Updated: 2015/01/22 10:27:59 by mriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*brand_new_list;
	t_list	*the_beginning;

	brand_new_list = NULL;
	the_beginning = NULL;
	if (f == NULL || lst == NULL)
		return (NULL);
	brand_new_list = f(lst);
	if (brand_new_list == NULL)
		return (NULL);
	the_beginning = brand_new_list;
	lst = lst->next;
	while (lst != NULL)
	{
		brand_new_list->next = f(lst);
		if (brand_new_list->next == NULL)
		{
			ft_lstdel(&the_beginning, &ft_bzero);
			return (NULL);
		}
		lst = lst->next;
		brand_new_list = brand_new_list->next;
	}
	return (the_beginning);
}
