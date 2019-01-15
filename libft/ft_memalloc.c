/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:45:07 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/15 11:38:21 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *point;

	if (!(point = (void *)malloc(sizeof(void) * size)))
	{
		return (0);
	}
	ft_bzero(point, size);
	return (point);
}
