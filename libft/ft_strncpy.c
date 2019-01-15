/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:44:29 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/10 16:42:32 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned char *tempdest;
	unsigned char *tempsrc;

	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	while (*tempsrc)
	{
		if (!len--)
			return (dest);
		*tempdest++ = *tempsrc++;
	}
	while (len--)
		*tempdest++ = '\0';
	return (dest);
}
