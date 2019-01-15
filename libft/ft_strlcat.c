/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:29:36 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/16 12:27:22 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	tempsize;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tempsize = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i] && i < size)
		i++;
	while (src[j] && i < size - 1)
		dest[i++] = src[j++];
	if (size != 0 && size >= tempsize)
		dest[i] = '\0';
	if (size < ft_strlen(dest))
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + tempsize);
}
