/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/12 16:54:47 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	*new_point(int x, int y)
{
	t_point *point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

int		place(t_tetri *tetri, t_grid *grid, int x, int y)
{
	int h;
	int w;
	int i;

	h = 0;
	i = 0;
	while (h < tetri[i].h)
	{
		w = 0;
		while (w < tetri[i].w)
		{
			if (tetri[i].piece[h][w] == '#' && grid->tab[x + h][y + w] != '.')
				return (0);
			w++;
		}
		h++;
	}
	place_piece(tetri, grid, new_point(x, y), tetri[i].alpha);
	return (1);
}

void	place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c)
{
	int h;
	int w;
	int i;

	h = 0;
	i = 0;
	while (h < tetri[i].h)
	{
		w = 0;
		while (w < tetri[i].w)
		{
			if (tetri[i].piece[h][w] == '#')
				grid->tab[point->y + w][point->x + h] = c;
			w++;
		}
		h++;
	}
	ft_memdel((void **)&point);
}

int		backtracking(t_tetri *tetri, t_grid *grid)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 0;
	if (tetri == NULL)
		return (-1);
	tetri = tetri->piece;
	while (y < (grid->size - tetri->h))
	{
		x = 0;
		while (x < (grid->size - tetri->w))
		{
			if (place(tetri, grid, x, y))
			{
				if (backtracking((tetri[i].piece == 0), grid))
					return (1);
				else
					place_piece(tetri, grid, new_point(x, y), '.');
				x++;
			}
		}
		y++;
	}
	return (0);
}

int		solve_grid(t_tetri *tetri)
{
	t_grid	*grid;
	int		size;

	size = righ_grid(count_tetri(tetri) * 4);
	grid = init_grid(size);
	while(!backtracking(tetri, grid))
	{
		size++;
		free_grid(grid);
		grid = init_grid(size);
	}
	return(grid);
}
