/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:10:43 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/15 12:26:31 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;

	str = NULL;
	size = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_strcpy(str, s1);
	return (str);
}
