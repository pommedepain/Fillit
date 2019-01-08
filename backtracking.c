/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/08 18:32:32 by pommedepin       ###   ########.fr       */
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

/*
** Fonction qui vérifie si aux coordonnées choisies, il n'y a pas déjà un tétri de placé.
** Si c'est le cas, il renvoie 0 et cherche d'autres coordonnées. 
** Sinon, il les garde en mémoire et part dans la fonction place_piece.
*/
int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y, int index)
{
	int i;
	int j;

	i = 0;
	while (i < (tetri[index].w))
	{
		j = 0;
		while (j < tetri[index].h)
		{
			// peut-être pb à checker dans la vérif sur tetri[index].piece[j][i] si on est sur un tétri de w de 1 car dans ce cas le check se fait au mauvais indexage ?
			if (tetri[index].piece[j][i] == '#' && grid->tab[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	place_piece(tetri, grid, new_point(x, y), tetri[index].alpha, index);
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
		//printf("tetri[index].w = %d\n", tetri[index].w);
		//printf("i = %d\n", i + 1);
		while (j < tetri[index].h)
		{
			//printf("tetri[index].h = %d\n", tetri[index].h);
			//printf("j = %d\n", j);
			if (tetri[index].piece[j][i] == '#')
				grid->tab[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)point);
}

int		backtracking(t_grid *grid, t_tetri *tetri/*, int index*/)
{
	int y;
	int x;
	int index;

	y = 0;
	index = 0;
	while (y < (grid->size - tetri[index].h + 1)) // size = 4; le +1 c'est pour que si la grille est initialisée à 4 et que le tétri fait 4 de h, il puisse etre placé quand même car il rentre tout pile
	{
		x = 0;
		while (x < (grid->size - tetri[index].w + 1))
		{
			if (choose_place_grid(&tetri[index], grid, x, y, index))
			{
				if (backtracking(grid, &tetri[index]) && tetri[index].piece == NULL) //&& tetri[index].end == 0)
					return (1);
				else
					place_piece(&tetri[index], grid, new_point(x, y), '.', index);
			}
			x++;
		}
		y++;
		index++;
	}
	return (0);
}

t_grid	*solve_grid(t_tetri *tetri)
{
	t_grid	*grid;
	int		size;
	int		count;

	count = tetri_count(tetri);
	size = right_grid(count * 4);
	grid = init_grid(size);
	/*ft_putstr(tetri[0].piece[4]);
	ft_putchar('\n');*/
	while ((backtracking(grid, tetri)) != 1) //&& tetri[index].end != 0))
	{
		size++;
		free_grid(grid);
		grid = init_grid(size);
	} 
	printf("ici\n");
	return (grid);
}
