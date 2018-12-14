/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/14 18:52:30 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_point	*new_point(int x, int y)
{
	t_point *point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y, int index)
{
	int h;
	int w;

	h = 0;
	while (h < tetri[index].h)
	{
		w = 0;
		while (w < tetri[index].w)
		{
			if (tetri[index].piece[h][w] == '#' && grid->tab[x + h][y + w] != '.')
				return (0);
			w++;
		}
		h++;
	}
	place_piece(tetri, grid, new_point(x, y), tetri->alpha, index);
	return (1);
}

void	place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c, int index)
{
	int h;
	int w;

	h = 0;
	while (h < tetri[index].h)
	{
		w = 0;
		while (w < tetri[index].w)
		{
			if (tetri[index].piece[h][w] == '#')
				grid->tab[point->y + w][point->x + h] = c;
			w++;
		}
		h++;
	}
	ft_memdel((void **)&point);
}

int		backtracking(t_tetri *tetri, t_grid *grid, int index)
{
	int y;
	int x;

	y = 0;
	//ft_putstr("ici");
	while (y < (grid->size - tetri->h + 1))
	{
		x = 0;
		while (x < (grid->size - tetri->w + 1))
		{
			if (choose_place_grid(tetri, grid, x, y, index))
			{
				if (backtracking(tetri, grid, index))
					return (1);
				else
					place_piece(tetri, grid, new_point(x, y), '.', index);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_grid	*solve_grid(t_tetri *tetri)
{
	t_grid	*grid;
	int		size;
	int		index;
	int		ret;

	ret = 0;
	index = tetri->index;
	printf("index = %d\n", index);
	size = right_grid(index * 4); // = right_grid(6 * 4) = 24 puis == 5
	grid = init_grid(size);
	while(!backtracking(tetri, grid, index))
	{
		//printf("ici");
		size++;
		index--;
		free_grid(grid);
		grid = init_grid(size);
	}
	return (grid);
}
