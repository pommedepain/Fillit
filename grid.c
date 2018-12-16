/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:11:00 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/16 21:44:16 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	free_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
	{
		ft_memdel((void **)&(grid->tab[i]));
		i++;
	}
	ft_memdel((void **)&(grid->tab));
	ft_memdel((void **)&grid);
}

void	print_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
	{
		ft_putstr(grid->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

t_grid	*init_grid(int size) // peut-etre a simplifier avec memset
{
	t_grid	*grid; 
	int		i;
	int		j;

	i = 0;
	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	grid->size = size;
	printf("size de init = %d\n", size);
	grid->tab = (char **)ft_memalloc(sizeof(char *) * size);
	while (i < size)
	{
		grid->tab[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			grid->tab[i][j] = '.';
			j++;
		}
		i++;
	}
	ft_print_words_tables(grid->tab);
	return (grid);
}

/*int		count_tetri(t_tetri *tetri)
{
	int i;

	i = 0;
	i = tetri->index;
	return (i);
}*/
	
/*int		right_grid(int nb)
{
	int size;

	size = 2;
	while (size * size < nb)
		size++;
	return (size);
}*/

int			right_grid(int nb)
{
	int racine;

	racine = 1;
	while (racine * racine < nb)
		racine++;
	if (racine * racine == (int)nb)
	   return (racine);
	else
		return (racine);
}
