/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:50:39 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/09 19:05:28 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *temps1;
	unsigned char *temps2;

	temps1 = (unsigned char *)s1;
	temps2 = (unsigned char *)s2;
	while (n--)
	{
		if (*temps1 != *temps2)
		{
			return (*temps1 - *temps2);
		}
		temps1++;
		temps2++;
	}
	return (0);
}
