/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:26:46 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/15 19:29:50 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_letter_count(char **split, char *s, char c)
{
	int letter;
	int word;
	int i;

	i = 0;
	letter = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			letter++;
			i++;
		}
		split[word] = (char *)malloc(sizeof(char) * (letter + 1));
		while (s[i] == c && s[i])
			i++;
		letter = 0;
		word++;
	}
}
