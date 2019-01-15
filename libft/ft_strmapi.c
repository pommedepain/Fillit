/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:14:31 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/15 12:00:37 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*temp;
	size_t			size;

	if (!s || !f)
		return (0);
	i = 0;
	size = ft_strlen(s);
	if (!(temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (s[i])
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[size] = '\0';
	return (temp);
}
