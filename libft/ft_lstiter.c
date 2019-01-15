/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:23:05 by pommedepin        #+#    #+#             */
/*   Updated: 2018/11/19 13:28:06 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(t_list *elem))
{
	if (!list)
		return ;
	if (list->next)
		ft_lstiter(list->next, f);
	f(list);
}
