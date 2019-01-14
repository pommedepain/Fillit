/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/14 16:31:44 by psentilh         ###   ########.fr       */
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

int				try_pos(t_grid *grid, t_tetri *tetri, t_point *point/*int x, int y*/)
{
	int ret;

	ret = 0;
	while (point->y < (grid->size - tetri->h + 1))
	{
		point->x = 0;
		while (point->x < (grid->size - tetri->w + 1))
		{
			printf("TP index = %d\n", tetri->index);
			if ((ret = choose_place_grid(tetri, grid, point->x, point->y)) != SUCCESS)
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
	int ret;

	ret = 0;
	while (point->y < (grid->size - tetri->h + 1))
	{
		point->x = 0;
		while (point->x < (grid->size - tetri->w + 1))
		{
			printf("NP index = %d\n", tetri->index);
			if ((ret = choose_place_grid(tetri, grid, point->x, point->y)) != SUCCESS)
				point->x++;
			else
				return (point);
				//return (SUCCESS);
		}
		point->y++;
	}
	point = NULL;
	//return (FAILURE);
	return (point);
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
			{
				grid->tab[j][i] = '.';
				printf("RM j = %d & i = %d\n", j, i);
			}
			i++;
		}
		j++;
	}
	printf("\nGrille tetri_rm :\n");
	ft_print_words_tables(grid->tab);
	//ft_putchar('\n');
	
}
/*
**si il n est pas placable, je trouve une autre position
**sinon (donc si il est placable), je le place et je reinitilise les coordonnees a 0
**relance foncion avec coordonnees 0 et tetri[index++]
**Si backtracking renvoit erreur, enleve le tetri actuel et relance la fonction avec position suivante et tetri actuel.
*/
int				backtracking(t_grid *grid, t_tetri *tetri, int x, int y)
{
	int		index;
	t_point *tp;
	t_point	*np;

	index = 0;
	tp = NULL;
	np = NULL;
	if (tetri[index].piece == NULL)
			return (SUCCESS);
	//peut-etre refaire en sorte que try_pos et New_pos soient les mêmes fonctions avec le même retour pour que try_pos soit un jour égal à SUCCESS et sortir de la loop infinie
	while ((try_pos(grid, &tetri[index], tp = new_point(x, y))) == FAILURE)
	{
		printf("\nERASE\n");
		tetri_rm(grid, &tetri[--index]);
		printf("1 erase tp.x = %d & tp.y = %d\n\n", tp->x, tp->y);
		// vaudra toujours SUCCESS car il arrivera a poser le tetri mais trouver comment lui dire que s'il ne peut pas poser le suivant, tenter une autre pos pour l'actuel.
		if ((np = new_pos(grid, &tetri[index], new_point(x, ++y))) != NULL)
		{
			y = 0;
			printf("x = %d & y = %d\n", x, y);
			printf("tp->x = %d & tp->y = %d\n", tp->x, tp->y);
			if ((try_pos(grid, &tetri[++index], new_point(x, y))) == FAILURE)
			{
				printf("index BT = %d\n", tetri->index);
				printf("\nERASE 2\n");
				tetri_rm(grid, &tetri[--index]);
				np->y++;
				printf("np->y = %d\n", np->y);
				if (try_pos(grid, &tetri[index++], np) == FAILURE)
					return (FAILURE);
				y = 0;
			}
			else
				return (SUCCESS);
		}
		else
			return (FAILURE);
		if (tetri->index < 0)
			return (FAILURE);
	}
	index++;
	printf("coucou\n");
	while ((backtracking(grid, &tetri[index], x, y)) == FAILURE)
	{
		printf("ERROR\n\n");
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
	printf("\nFin :\n");
	return (grid);
}
