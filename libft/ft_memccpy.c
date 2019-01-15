/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:49:53 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/09 19:18:49 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *tempdest;
	unsigned char *tempsrc;

	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	while (n--)
	{
		*tempdest = *tempsrc;
		if (*tempdest == (unsigned char)c)
			return (tempdest + 1);
		tempdest++;
		tempsrc++;
	}
	return (0);
}
