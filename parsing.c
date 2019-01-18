/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:49:49 by cfauvell          #+#    #+#             */
/*   Updated: 2019/01/18 16:28:25 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check tetriminos (secondary function)
*/

int		ft_check_pattern(char **tab, int y, int x, int count)
{
	y != 0 && tab[y - 1][x] == '#' ? count++ : 0;
	x != 0 && tab[y][x - 1] == '#' ? count++ : 0;
	x != 3 && tab[y][x + 1] == '#' ? count++ : 0;
	y != 3 && tab[y + 1][x] == '#' ? count++ : 0;
	return (count);
}

/*
** Check tetriminos (principal function)
*/

int		check_tetri(char **tab)
{
	int x;
	int y;
	int hash;
	int count;

	y = -1;
	hash = 0;
	count = 0;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (tab[y][x] != '.' && tab[y][x] != '#')
				return (0);
			if (tab[y][x] == '#')
			{
				hash++;
				count = ft_check_pattern(tab, y, x, count);
			}
		}
		if (x != 4)
			return (0);
	}
	return (y == 4 && hash == 4 && count >= 6);
}

// Fait 27 lignes
void	min_max(t_tetri *tetri, t_point *min, t_point *max, int index)
{
	int		i;
	char	*str;

	str = ft_strnew(21);
	i = 0;
	while (i < 4)
	{
		str = ft_strcat(str, tetri[index].piece[i++]);
		str = ft_strcat(str, "\n");
	}
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
	free(str);
}

t_tetri	*tetri_h_w(t_tetri *tetri)
{
	t_point *min;
	t_point *max;
	int		index;

	index = tetri_count(tetri) - 1;
	while (index != -1)
	{
		min = new_point(3, 3);
		max = new_point(0, 0);
		min_max(tetri, min, max, index);
		tetri[index].h = max->y - min->y + 1;
		tetri[index].w = max->x - min->x + 1;
		ft_memdel((void **)&min);
		ft_memdel((void **)&max);
		index--;
	}
	return (tetri);
}

char	**particular_l2(void)
{
	char *clear;
	char **final;

	clear = ".#...#..##......";
	final = tab_filling(clear);
	return (final);
}
