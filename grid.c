/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:11:00 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/21 14:31:57 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_grid(t_grid *grid)
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

void		print_grid(t_grid *grid)
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

/*
** Initilize a grid at the minimum size possible based on the
** number of tetris in the file descriptor.
*/

t_grid		*init_grid(int size)
{
	t_grid	*grid;
	int		i;

	i = 0;
	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	grid->size = size;
	grid->tab = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		grid->tab[i] = ft_strnew(size);
		ft_memset((void *)grid->tab[i], '.', grid->size);
		i++;
	}
	return (grid);
}

/*
** Cumputes the number of tetris
*/

int			tetri_count(t_tetri *tetri)
{
	int	i;

	i = 0;
	while (tetri[i].piece)
		i++;
	return (i);
}

/*
** Computes the minimum size possible of the grid.
*/

int			right_grid(int nb)
{
	int size;

	size = 1;
	while (size * size < nb)
		size++;
	return (size);
}
