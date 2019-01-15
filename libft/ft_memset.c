/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:01:22 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/09 14:25:00 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char *temp;

	temp = (unsigned char *)str;
	while (len--)
	{
		*temp++ = (unsigned char)c;
	}
	return (str);
}
