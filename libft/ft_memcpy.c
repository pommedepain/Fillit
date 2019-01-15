/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:04:06 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/09 16:25:00 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tempdst;
	unsigned char	*tempsrc;

	tempdst = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	while (n--)
	{
		*tempdst++ = *tempsrc++;
	}
	return (dest);
}
