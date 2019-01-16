/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FUCK_BACKTRACKING.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:52:23 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/16 18:34:29 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				try_pos(t_grid *grid, t_tetri *tetri, t_point *point)
{
	while (point->y < (grid->size - tetri->h + 1))
	{
		point->x = 0;
		while (point->x < (grid->size - tetri->w + 1))
		{
			if ((choose_place_grid(tetri, grid, point->x, point->y)) == NULL)
				point->x++;
			else
				return (SUCCESS);
		}
		point->y++;
	}
	return (FAILURE);
}

t_point		*new_pos(t_grid *grid, t_tetri *tetri, t_point *point)
{
	while (point->y < (grid->size - tetri->h + 1))
	{
		point->x = 0;
		while (point->x < (grid->size - tetri->w + 1))
		{
			if ((choose_place_grid(tetri, grid, point->x, point->y)) == NULL)
				point->x++;
			else
				return (point);
		}
		point->y++;
	}
	point = NULL;
	return (point);
}

t_point		*choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y)
{
	t_point *point;

	point = NULL;
	point->x = 0;
	while (point->x < tetri->w)
	{
		point->y = 0;
		while (point->y < tetri->h)
		{
			if (tetri->piece[point->y][point->x] == '#' && grid->tab[y + point->y][x + point->x] != '.')
			{
				//printf("point.y = %d & point.x = %d\n", point->y, point->x);
				return (point);
			}
			point->y++;
		}
		point->x++;
	}
	point = NULL;
	return (point);
}

// Essayer de deconnecter try_pos et new_pos de place_piece et le faire plutot dans le backtrcking !
int		backtracking(t_grid *grid, t_tetri *tetri, t_point *np)
{
	int x;
	int y;
	int index;

	x = 0;
	y = 0;
	index = 0;
	np = NULL;
	printf("index = %d\n", tetri->index);
	printf("1 x = %d & y = %d\n", x, y);
	if (tetri[index].piece == NULL)
	{
		printf("\nSUCCESS\n");
		return (SUCCESS);
	}
	if ((np = new_pos(grid, &tetri[index], new_point(x, y))) == NULL)
	{
		printf("\nBACKTRACK new pos\n");
		return (backtracking(grid, &tetri[index], new_point(x, ++y)));
	}
	printf("2 x = %d & y = %d\n", x, y);
	printf("np.x = %d & np.y = %d\n", np->x, np->y);
	place_piece(&tetri[index], grid, np->x, np->y, tetri[index].alpha);
	y = 0;
	printf("3 x = %d & y = %d\n", x, y);
	if (!backtracking(grid, &tetri[index++], new_point(x, y)))
	{
		printf("RM index = %d\n", tetri->index);
		tetri_rm(grid, tetri);
		return (backtracking(grid, &tetri[index], new_point(x, y++)));
	}
	return (SUCCESS);
}

t_grid	*solve_grid(t_tetri *tetri)
{
	t_grid	*grid;
	int		size;
	int		count;
	t_point *point;
	
	point = NULL;
	count = tetri_count(tetri);
	size = right_grid(count * 4);
	grid = init_grid(size);
	while (!(backtracking(grid, tetri, point)))
	{
		printf("size++\n");
		size++;
		free_grid(grid);
		grid = init_grid(size);
	} 
	printf("\nFin :\n");
	return (grid);
}
