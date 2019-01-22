/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:52:23 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/22 14:46:29 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Looks for a new set of coordinates to pass on to choose_place_grid
*/

t_point		*new_pos(t_grid *grid, t_point *point)
{
	point->x += 1;
	if (point->x > grid->size)
	{
		point->x = 0;
		point->y += 1;
		if (point->y > grid->size)
		{
			point = NULL;
			return (point);
		}
		return (point);
	}
	return (point);
}

/*
** Checks that the coordinates that it receives are valid to place
** the whole tetri
*/

t_point		*choose_place_grid(t_tetri *tetri, t_grid *grid, t_point *point)
{
	int x;
	int y;
	int nb_sharp;

	y = 0;
	nb_sharp = 0;
	while ((grid->size > y + point->y) && y < 4)
	{
		x = 0;
		while ((grid->size > x + point->x) && x < 4)
		{
			if ((tetri->piece[y][x] == '#')
				&& (grid->tab[point->y + y][point->x + x] == '.'))
				nb_sharp++;
			if (nb_sharp == 4)
				return (point);
			x++;
		}
		y++;
	}
	point = NULL;
	return (point);
}

/*
** Places a tetri on the grid at the coordinates that it receives
*/

t_grid		*place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c)
{
	int x;
	int y;
	int nb_sharp;

	y = 0;
	nb_sharp = 0;
	while ((grid->size > y + point->y) && y < 4)
	{
		x = 0;
		while ((grid->size > x + point->x) && x < 4)
		{
			if ((tetri->piece[y][x] == '#')
				&& (grid->tab[point->y + y][point->x + x] == '.'))
			{
				grid->tab[point->y + y][point->x + x] = c;
				nb_sharp++;
			}
			if (nb_sharp == 4)
				return (grid);
			x++;
		}
		y++;
	}
	grid = NULL;
	return (grid);
}

int			backtracking(t_grid *grid, t_tetri *tetri, t_point *np, int index)
{
	t_point		*point;

	point = new_point(0, 0);
	if ((index = stop_condition(&tetri[index], np)) != -1)
	{
		ft_memdel((void **)&point);
		return (index == SUCCESS);
	}
	index = 0;
	if ((choose_place_grid(&tetri[index], grid, np)) == NULL)
	{
		ft_memdel((void **)&point);
		return (backtracking(grid, &tetri[index], new_pos(grid, np), index));
	}
	grid = place_piece(&tetri[index], grid, np, tetri[index].alpha);
	if ((backtracking(grid, &tetri[index + 1], point, index)) == FAILURE)
	{
		ft_memdel((void **)&point);
		tetri_rm(grid, &tetri[index]);
		return (backtracking(grid, &tetri[index], new_pos(grid, np), index));
	}
	free_point(point);
	return (SUCCESS);
}

/*
** Main of the backtracking that's in charge of intializing and
** extending the grid if necessary.
*/

t_grid		*solve_grid(t_tetri *tetri)
{
	t_grid	*grid;
	int		size;
	int		count;
	t_point	*np;
	int		index;

	index = 0;
	np = new_point(0, 0);
	count = tetri_count(tetri);
	size = right_grid(count * 4);
	grid = init_grid(size);
	while (!(backtracking(grid, tetri, np, index)))
	{
		ft_memdel((void **)&np);
		size++;
		free_grid(grid);
		grid = init_grid(size);
		np = new_point(0, 0);
	}
	ft_memdel((void **)&np);
	return (grid);
}
