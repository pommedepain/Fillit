/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:52:53 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/18 20:38:24 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*temp;
	size_t	size;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	if (!(temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (s[i])
	{
		temp[i] = f(s[i]);
		i++;
	}
	temp[size] = '\0';
	return (temp);
}
