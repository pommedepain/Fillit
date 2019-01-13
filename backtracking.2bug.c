/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/13 22:41:22 by pommedepin       ###   ########.fr       */
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

int				try_pos(t_grid *grid, t_tetri *tetri, int x, int y)
{
	int ret;

	ret = 0;
	while (y < (grid->size - tetri->h + 1))
	{
		x = 0;
		while (x < (grid->size - tetri->w + 1))
		{
			printf("TP index = %d\n", tetri->index);
			if ((ret = choose_place_grid(tetri, grid, x, y)) != SUCCESS)
				x++;
			else
				return (SUCCESS);
		}
		y++;
	}
	return (FAILURE);
}

t_point				*new_pos(t_grid *grid, t_tetri *tetri, t_point *point)
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
		}
		point->y++;
	}
	point->x = -2;
	//point->y = -2;
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
	ft_putchar('\n');
	
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
	int		ret;
	t_point *point;

	ret = 0;
	index = 0;
	point = NULL;
	if (tetri[index].piece == NULL)
			return (SUCCESS);
	//peut-etre refaire en sorte que try_pos et New_pos soient les mêmes fonctions avec le même retour pour que try_pos soit un jour égal à SUCCESS et sortir de la loop infinie
	if ((ret = try_pos(grid, &tetri[index++], x, y)) == FAILURE)
	{
		printf("\nERASE\n");
		index--;
		tetri_rm(grid, &tetri[--index]);
		y += 2;
		printf("1 erase x = %d & y = %d\n", x, y);
		if ((point = new_pos(grid, &tetri[index], new_point(x, y))) != NULL)
		{
			printf("next index\n");
			try_pos(grid, &tetri[++index], x, y);
		}
		//try_pos(grid, &tetri[++index], x, y);
		printf("index BT = %d\n", tetri->index);
		if (tetri->index < 0)
			return (FAILURE);
		/*else if (tetri[index].piece == NULL)
		{
			printf("SUCCES\n\n");
			return (SUCCESS);
		}*/
	}
	printf("coucou\n");
	while ((ret = backtracking(grid, &tetri[index], x, y)) == FAILURE)
	{
		printf("ERROR\n\n");
		// trouver une maniere de recuperer les coordonnees x/y de choose_place pour effacer le bon tetri (avec new_point) OU creer une focntion tetri_rm qui lit la grille en reperant le char du tetri à effacer (et donc direct les bonnes coordonees)
		//place_piece(&tetri[--index], grid, x, y, '.');
		/*tetri_rm(grid, &tetri[--index]);
		printf("index BT = %d\n", index);
		new_pos(grid, &tetri[index], ++x, y);
		if (index < 0)
			return (FAILURE);*/
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
