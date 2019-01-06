/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/05 17:36:27 by pommedepin       ###   ########.fr       */
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
	//printf("index = %d\n", index);
	//printf("tetri->h = %d\n", tetri->h);
	//printf("tetri[index].h = %d\n", tetri[index].h);
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
	int		count;
	int		index;

	count = tetri_count(tetri);
	index = (count - 1);
	/*printf("tetri->alpha = %c\n", tetri->alpha);
	printf("tetri[index].alpha = %c\n", tetri[0].alpha);*/
	size = right_grid(count * 4); // = right_grid(6 * 4) = 24 puis == 5
	grid = init_grid(size);
	/*ft_print_words_tables(grid->tab);
	ft_putchar('\n');*/
	while((!backtracking(tetri, grid, index) && index == 0))
	{
		size++;
		free_grid(grid);
		grid = init_grid(size);
		index--;
		count++;
		/*printf("tetri->alpha = %c\n", tetri->alpha);
		printf("tetri[index].alpha = %c\n", tetri[0].alpha);*/
	}
	//arrive jusque là.
	return (grid);
}
