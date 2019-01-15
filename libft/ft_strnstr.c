/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:03:54 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/19 13:38:44 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystk, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystk);
	while (i < (len) && haystk[i])
	{
		j = 0;
		while (needle[j] == haystk[i + j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystk + i);
			j++;
		}
		i++;
	}
	return (0);
}
