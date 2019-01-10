/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/10 17:30:00 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Initialise un nouveau pointeur sur coordonnées.
** Utilisé dans min_max et choose_place.
*/
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

/*
** Fonction qui vérifie si aux coordonnées choisies, il n'y a pas déjà un tétri de placé.
** Si c'est le cas, il renvoie 0 et cherche d'autres coordonnées. 
** Sinon, il les garde en mémoire et part dans la fonction place_piece.
*/
int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y)
{
	int i;
	int j;

	i = 0;
	printf("index = %d\n", tetri->index);
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	while (i < tetri->w)
	{
		j = 0;
		while (j < tetri->h)
		{
			printf("char de tetri = %c\n", tetri->piece[j][i]);
			printf("char de tab = %c\n", grid->tab[y + j][x + i]);
			if (tetri->piece[j][i] == '#' && grid->tab[y + j][x + i] != '.')
				return (-1);
			j++;
		}
		i++;
	}
	//place_piece(tetri, grid, new_point(x, y), tetri->alpha);
	place_piece(tetri, grid, x, y, tetri->alpha);
	return (1);
}

/*
** Parcourt la grile sur le même principe que choose_place mais inscrit le tetri 
** avec les coordonnées envoyées à l'aide d'alpha.
*/
void	place_piece(t_tetri *tetri, t_grid *grid, int x, int y, char c)
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
				grid->tab[y + j][x + i] = c;
			j++;
		}
		i++;
	}
	//ft_memdel((void **)point);
	ft_print_words_tables(grid->tab);
	ft_putchar('\n');
}

/*
** Pendant qu'on parcourt la grille, on vérifie s'il y a une place pour le tetri en cours
** Si oui, et que tous les tetris sont placés, on renvoit 1.
** Sinon on place ce tetri et on passe au suivant.
** Si on a parcourut tous les tetris sans avoir reussi à tous les placer, on renvoie 0 pour rappeler la fonction avec une grille plus grande.
*/
/*int			backtracking(t_grid *grid, t_tetri *tetri)
{
	int y;
	int x;
	int index;

	y = 0;
	index = 0;
	while (y < (grid->size - tetri[index].h + 1))
	{
		if (tetri->piece == NULL)
			return (1);
		x = 0;
		while (x < (grid->size - tetri[index].w + 1))
		{
			if (choose_place_grid(&tetri[index], grid, x, y))
			{
				if (backtracking(grid, &tetri[++index]))
					return (1);
				else
					place_piece(&tetri[index], grid, new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}*/

int				new_pos(t_grid *grid, t_tetri *tetri, int x, int y)
{
	int ret;

	ret = 0;
	while (y < (grid->size - tetri->h + 1))
	{
		x = 0;
		while (x < (grid->size - tetri->w + 1))
		{
			//printf("index = %d\n", tetri->index);
			//printf("x = %d\n", x);
			//printf("y = %d\n", y);
			if ((ret = choose_place_grid(tetri, grid, x, y)) != 1)
				x++;
			else
				return (1);
		}
		y++;
	}
	return (0);
}

int				backtracking(t_grid *grid, t_tetri *tetri)
{
	int y;
	int x;
	int index;
	int ret;

	y = 0;
	x = 0;
	ret = 0;
	index = 0;
	if (tetri[index].piece == NULL)
			return (1);
	if ((ret = choose_place_grid(&tetri[index], grid, x, y)) != 1)
	{
		if (!new_pos(grid, &tetri[index], x, y))
			return (-1);
	}	
	else
	{
		if (!backtracking(grid, &tetri[++index]))
		{
			printf("2eme x = %d & y = %d\n", x, y);
			place_piece(&tetri[index], grid, x, y, '.');
		}
		else
			return (1);
	}
	return (0);
}

/*
** Initilise une grille remplie de '.' en calculant la taille minimale possible basée sur le nbre de tetri dans la struct.
** Si le backtracking ne peut être résoud avec cette taille, l'agrandit jusqu'à résolution.
*/
t_grid	*solve_grid(t_tetri *tetri)
{
	t_grid	*grid;
	int		size;
	int		count;
	int		ret;

	count = tetri_count(tetri);
	size = right_grid(count * 4);
	grid = init_grid(size);
	/*ft_print_words_tables(grid->tab);
	ft_putchar('\n');*/
	while ((ret = backtracking(grid, tetri)) == -1)
	{
		size++;
		free_grid(grid);
		grid = init_grid(size);
	} 
	//printf("ici\n");
	return (grid);
}
