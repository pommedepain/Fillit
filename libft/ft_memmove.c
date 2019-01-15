/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:59:13 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/09 16:19:35 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tempdest;
	unsigned char	*tempsrc;

	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	if (dest > src)
		while (len--)
			tempdest[len] = tempsrc[len];
	else
		while (len--)
		{
			*tempdest++ = *tempsrc++;
		}
	return (dest);
}
