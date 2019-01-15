/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_filling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:27:06 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/15 19:27:17 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_tab_filling(char **split, char *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (split[i])
	{
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && s[k])
		{
			split[i][j] = s[k];
			j++;
			k++;
		}
		split[i][j] = '\0';
		i++;
		k++;
		j = 0;
	}
}
