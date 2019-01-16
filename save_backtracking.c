/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_backtracking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:59:41 by pommedepin        #+#    #+#             */
/*   Updated: 2019/01/16 16:40:34 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_point	*new_point(int x, int y)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = -1;
	point->y = -1;
	point->x = x;
	point->y = y;
	return (point);
}

int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->w)
	{
		j = 0;
		while (j < tetri->h)
		{
			if (tetri->piece[j][i] == '#' && grid->tab[y + j][x + i] != '.')
				return (ERROR);
			j++;
		}
		i++;
	}
	place_piece(tetri, grid, new_point(x, y), tetri->alpha);
	return (SUCCESS);
}

void		place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->w)
	{
		j = 0;
		while (j < tetri->h)
		{
			if (tetri->piece[j][i] == '#')
				grid->tab[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	printf("\nGrille place_piece :\n");
	ft_print_words_tables(grid->tab);
	ft_putchar('\n');
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
				grid->tab[j][i] = '.';
			i++;
		}
		j++;
	}
	printf("\nGrille tetri_rm :\n");
	ft_print_words_tables(grid->tab);	
}

/*
** Pendant qu'on parcourt la grille, on vérifie s'il y a une place pour le tetri en cours
** Si oui, et que tous les tetris sont placés, on renvoit 1.
** Sinon on place ce tetri et on passe au suivant.
** Si on a parcourut tous les tetris sans avoir reussi à tous les placer, on renvoie 0 pour rappeler la fonction avec une grille plus grande.
*/

int			backtracking(t_grid *grid, t_tetri *tetri)
{
	int y;
	int x;
	int index;
	t_point *np;

	y = 0;
	index = 0;
	np = NULL;
	while (y < (grid->size - tetri[index].h + 1))
	{
		printf("y = %d\n", y);
		if (tetri[index].piece == NULL)
		{
			printf("\nSUCCESS\n");
			return (SUCCESS);
		}
		x = 0;
		while (x < (grid->size - tetri[index].w + 1))
		{
			printf("x = %d\n", x);
			if (choose_place_grid(&tetri[index], grid, x, y))
			{
				if (backtracking(grid, &tetri[++index]))
				{
					printf("\nSUCCESS\n");
					return (SUCCESS);
				}
				else
				{
					printf("Erasing...\n");
					tetri_rm(grid, &tetri[--index]);
					printf("new index = %d\n", tetri[index].index);
				}
			}
			x++;
		}
		y++;
	}
	return (FAILURE);
}

t_grid	*solve_grid(t_tetri *tetri)
{
	t_grid	*grid;
	int		size;
	int		count;
	int		ret;
	count = tetri_count(tetri);
	size = right_grid(count * 4);
	grid = init_grid(size);
	while ((ret = backtracking(grid, tetri)) == FAILURE)
	{
		printf("size++\n");
		size++;
		free_grid(grid);
		grid = init_grid(size);
	} 
	printf("\nFin :\n");
	return (grid);
}
