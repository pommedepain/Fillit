/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:07:17 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/15 20:19:11 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		word;
	char	**split;

	if (!s)
		return (0);
	word = ft_word_count((char *)s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (word + 1))))
		return (0);
	split[word] = 0;
	if (word == 0)
	{
		split[0] = 0;
		return (split);
	}
	ft_letter_count(split, (char *)s, c);
	ft_tab_filling(split, (char *)s, c);
	return (split);
}
