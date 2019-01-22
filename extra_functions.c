/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/22 13:05:47 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Initialize a pointer with coordinates to move on the grid.
*/

t_point		*new_point(int x, int y)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = 0;
	point->y = 0;
	point->x = x;
	point->y = y;
	return (point);
}

/*
** Erase a tetri already placed on the grid.
*/

void		tetri_rm(t_grid *grid, t_tetri *tetri)
{
	int i;
	int j;

	j = 0;
	while (j < grid->size)
	{
		i = 0;
		while (i < grid->size)
		{
			if (grid->tab[j][i] == tetri->alpha)
			{
				grid->tab[j][i] = '.';
			}
			i++;
		}
		j++;
	}
}

/*
** Free the entire tetri structure
*/

void		free_tetri(t_tetri *tetri)
{
	int i;
	int y;

	i = 0;
	while (tetri[i].piece)
	{
		y = 0;
		while (tetri[i].piece[y])
		{
			free(tetri[i].piece[y]);
			y++;
		}
		free(tetri[i].piece);
		i++;
	}
	free(tetri);
}

/*
** Divide a string into a char array (works for one tetriminos)
*/

int			sort_tetri1(char *str, t_tetri *test, int index)
{
	if (!(str = clear_string1(str)))
		free(str);
	if (sort_particular_case(str, test, index) == 1)
	{
		free(str);
		return (1);
	}
	str = clear_string2(str);
	if (!(test[0].piece = tab_filling(str)))
		return (-1);
	free(str);
	return (1);
}

/*
** the 6th particular case (see sort_file.3.c)
*/

char		**particular_l2(void)
{
	char *clear;
	char **final;

	clear = ".#...#..##......";
	final = tab_filling(clear);
	return (final);
}
