/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:48:23 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/14 15:00:48 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	str[len] = '\0';
	i = 0;
	while (len--)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	return (str);
}
