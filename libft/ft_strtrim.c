/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:39:20 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/15 12:05:17 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	unsigned int	start;
	size_t			end;

	if (!s)
		return (0);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		&& s[start])
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		&& s[end] && end > start)
		end--;
	return (ft_strsub(s, start, (end - start) + 1));
}
