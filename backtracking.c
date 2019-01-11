/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/11 19:03:31 by psentilh         ###   ########.fr       */
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
	while (i < tetri->w)
	{
		j = 0;
		while (j < tetri->h)
		{
			printf("Choose_place :\n");
			printf("char de tetri = %c & de tab = %c\n", tetri->piece[j][i], grid->tab[y + j][x + i]);
			if (tetri->piece[j][i] == '#' && grid->tab[y + j][x + i] != '.')
				return (ERROR);
			j++;
		}
		i++;
	}
	printf("x = %d & y = %d\n", x, y);
	place_piece(tetri, grid, x, y, tetri->alpha);
	return (SUCCESS);
}

/*
** Parcourt la grile sur le même principe que choose_place mais inscrit le tetri 
** avec les coordonnées envoyées à l'aide d'alpha.
*/

void		place_piece(t_tetri *tetri, t_grid *grid, int x, int y, char c)
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
	printf("\nGrille place_piece :\n");
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
			printf("index = %d\n", tetri->index);
			if ((ret = choose_place_grid(tetri, grid, x, y)) != SUCCESS)
				x++;
			else
				return (SUCCESS);
		}
		y++;
	}
	return (FAILURE);
}

/*
**si il n est pas placable, je trouve une autre position
**sinon (donc si il est placable), je le place et je reinitilise les coordonnees a 0
**relance foncion avec coordonnees 0 et tetri[index++]
**Si backtracking renvoit erreur, enleve le tetri actuel et relance la fonction avec position suivante et tetri actuel.
*/

int				backtracking(t_grid *grid, t_tetri *tetri, int x, int y)
{
	int index;
	int ret;

	ret = 0;
	index = 0;
	if (tetri[index].piece == NULL)
			return (SUCCESS);
	new_pos(grid, &tetri[index++], x++, y);
	if ((ret = backtracking(grid, &tetri[index],x , y)) == ERROR)
	{
		place_piece(&tetri[index], grid, x, y, '.');
		new_pos(grid, &tetri[index], x++, y);
	}
	printf("ici\n");
	return (SUCCESS);
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
	int		x;
	int		y;

	x = 0;
	y = 0;
	count = tetri_count(tetri);
	size = right_grid(count * 4);
	grid = init_grid(size);
	while ((ret = backtracking(grid, tetri, x, y)) == ERROR)
	{
		size++;
		free_grid(grid);
		grid = init_grid(size);
	} 
	printf("Fin :\n");
	return (grid);
}
