/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:26:00 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/15 19:35:51 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_word_count(char *s, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word);
}
