/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:04:20 by pommedepin        #+#    #+#             */
/*   Updated: 2018/11/18 17:23:44 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alist, void (*del)(void *, size_t))
{
	if ((*alist)->next)
		ft_lstdel(&(*alist)->next, del);
	ft_lstdelone(&(*alist), del);
}
