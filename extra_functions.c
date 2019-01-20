/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/18 18:55:24 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Initialise un nouveau pointeur sur coordonnées.
** Utilisé dans min_max et choose_place.
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

void		free_all(t_tetri *test)
{
	int i;
	int y;

	i = 0;
	while (test[i].piece)
	{
		y = 0;
		while (test[i].piece[y])
		{
			free(test[i].piece[y]);
			y++;
		}
		free(test[i].piece);
		i++;
	}
	free(test);
}

void		ft_end_of_prog(t_grid *grid, t_tetri *tetri)
{
	print_grid(grid);
	free_grid(grid);
	free_all(tetri);
}

void		free_point(t_point **point)
{
	if (*point)
	{
		free(*point);
		//free(&point);
		*point = NULL;
	}
}
