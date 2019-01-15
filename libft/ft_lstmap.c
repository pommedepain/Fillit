/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:31:07 by pommedepin        #+#    #+#             */
/*   Updated: 2018/11/18 20:49:58 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new;

	if (!list)
		return (NULL);
	temp = f(list);
	new = temp;
	while (list->next)
	{
		list = list->next;
		if (!(temp->next = f(list)))
		{
			free(temp->next);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new);
}
