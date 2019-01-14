/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file.2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:00:54 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/14 16:07:15 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Remove \n from string
*/

char	*clear_string1(char *tab)
{
	char	*clear;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!(clear = (char *)malloc(sizeof(char) * 17)))
		return (NULL);
	while (i < 20)
	{
		if (tab[i] == '\n')
			i++;
		clear[y++] = tab[i++];
	}
	free(tab);
	return (clear);
}

/*
** Recreate a string with the tetriminos on the top left
** of the grid (to help backtracking)
*/

char	*clear_string2(char *tab)
{
	char	*clear;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!(clear = (char *)malloc(sizeof(char) * 17)))
		return (NULL);
	while (tab[i] != '#' && tab[i])
		i++;
	while (tab[i])
		clear[y++] = tab[i++];
	while (y < 16)
		clear[y++] = '.';
	clear[y] = '\0';
	free(tab);
	return (clear);
}

/*
** Convert the string in a char array
*/

char	**tab_filling(char *tab)
{
	char	**final;
	int		i;
	int		y;
	int		k;

	i = 0;
	y = 0;
	k = 0;
	if (!(final = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	final[4] = 0;
	while (i != 4)
	{
		if (!(final[i] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
		final[i][4] = 0;
		y = 0;
		while (y != 4)
			final[i][y++] = tab[k++];
		i++;
	}
	return (final);
}

/*
** Handle particular tetriminos who don't work normally
*/

int		sort_particular_case(char *tmp2, t_tetri *test, int i)
{
	if (ft_strstr(tmp2, "#..###"))
		test[i].piece = particular_t1();
	else if (ft_strstr(tmp2, "#.###"))
		test[i].piece = particular_l();
	else if (ft_strstr(tmp2, "#..##...#"))
		test[i].piece = particular_t2();
	else if (ft_strstr(tmp2, "#...#..##"))
		test[i].piece = particular_l2();
	else if (ft_strstr(tmp2, "##.##"))
		test[i].piece = particular_s();
	else if (ft_strstr(tmp2, "#..##..#"))
		test[i].piece = particular_s2();
	else
		return (0);
	return (1);
}
