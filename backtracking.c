/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/12 15:32:40 by pommedepin       ###   ########.fr       */
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
			printf("CP char tetri = %c & tab = %c\n", tetri->piece[j][i], grid->tab[y + j][x + i]);
			if (tetri->piece[j][i] == '#' && grid->tab[y + j][x + i] != '.')
				return (ERROR);
			j++;
		}
		i++;
	}
	printf("CP x = %d & y = %d\n", x, y);
	place_piece(tetri, grid, x, y, tetri->alpha);
	//place_piece(tetri, grid, new_point(x, y), tetri->alpha);
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

int				new_pos(t_grid *grid, t_tetri *tetri, int x, int y)
{
	int ret;

	ret = 0;
	while (y < (grid->size - tetri->h + 1))
	{
		x = 0;
		while (x < (grid->size - tetri->w + 1))
		{
			printf("NP index = %d\n", tetri->index);
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
	if ((ret = new_pos(grid, &tetri[index++], x, y)) == FAILURE)
	{
		printf("FAIL\n\n");
		return (FAILURE);
	}
	while ((ret = backtracking(grid, &tetri[index], x, y)) == FAILURE && index > 0)
	{
		/*printf("ERASE\n\n");
		// trouver une maniere de recuperer les coordonnees x/y de choose_place pour effacer le bon tetri (avec new_point) OU creer une focntion tetri_rm qui lit la grille en reperant le char du tetri à effacer (et donc direct les bonnes coordonees)
		place_piece(&tetri[--index], grid, x, y, '.');
		printf("index BT = %d\n", index);
		new_pos(grid, &tetri[index], x, y);
		if (index > 0)*/
			return (FAILURE);
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
	while ((ret = backtracking(grid, tetri, x, y)) == FAILURE)
	{
		printf("size++\n");
		size++;
		free_grid(grid);
		grid = init_grid(size);
	} 
	printf("Fin :\n");
	return (grid);
}
