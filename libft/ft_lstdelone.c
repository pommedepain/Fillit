/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:35:57 by pommedepin        #+#    #+#             */
/*   Updated: 2018/11/18 17:02:30 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alist, void (*del)(void *, size_t))
{
	del((*alist)->content, (*alist)->content_size);
	free(*alist);
	*alist = NULL;
}
