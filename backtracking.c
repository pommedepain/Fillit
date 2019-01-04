/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/04 16:43:53 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_point	*new_point(int x, int y)
{
	t_point *point;

	point = (t_point *)ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

/*t_tetri	*tetri_init(t_tetri *tetri, int h, int w)
{
	tetri = (t_tetri *)malloc(sizeof(t_tetri));
	tetri->h = h;
	tetri->w = w;
	return (tetri);
}*/

/*void	min_max(t_tetri *tetri, t_point *min, t_point *max)
{
	int index;
	int i;

	i = 0;
	index = tetri->index;
	while (i < 20)
	{
		if ((int)tetri[index].piece == '#')//crée potentiellement pb de segv à cause du cast
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
}*/

/*t_tetri	*tetri_h_w(t_tetri *tetri)
{
	t_point *min;
	t_point *max;

	min = new_point(3, 3);
	max = new_point(0, 0);
	min_max((t_tetri *)tetri->piece, min, max);
	tetri->h = max->x - min->x + 1;
	tetri->w = max->y - min->y + 1;
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri);
}*/

int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y, int index)
{
	int i;
	int j;

	i = 0;
	while (i < tetri[index].w)
	{
		j = 0;
		while (j < tetri[index].h)
		{
			if (tetri[index].piece[j][i] == '#' && grid->tab[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	place_piece(tetri, grid, new_point(x, y), tetri->alpha, index);
	return (1);
}

void	place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c, int index)
{
	int i;
	int j;

	i = 0;
	while (i < tetri[index].w)
	{
		j = 0;
		while (j < tetri[index].h)
		{
			if (tetri[index].piece[j][i] == '#')
				grid->tab[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

int		backtracking(t_tetri *tetri, t_grid *grid, int index)
{
	int y;
	int x;

	y = 0;
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

	index = tetri_count(tetri);
	size = right_grid(index * 4); // = right_grid(6 * 4) = 24 puis == 5
	grid = init_grid(size);
	//ft_print_words_tables(grid->tab);
	while(!backtracking(tetri, grid, index))
	{
		size++;
		free_grid(grid);
		grid = init_grid(size);
		//index--;
	}
	return (grid);
}
