/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:11:00 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/12 14:31:57 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
	{
		ft_memdel((void **)&(grid->tab[i]));
		i++;
	}
	ft_memdel((void **)&grid);
}

void	print_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < grid->size)
	{
		ft_putstr(grid[i].tab);
		ft_putchar('\n');
		i++;
	}
}

t_grid	*init_grid(int size)
{
	t_grid	*grid; 
	int		h;
	int		w;

	h = 0;
	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	grid->size = size;
	grid->tab = (char **)ft_memalloc(sizeof(char *) * size);
	while (h < size)
	{
		grid->tab[h] = ft_strnew(size);
		w = 0;
		while (w < size)
		{
			grid->tab[h][w] = '.';
			w++;
		}
		h++;
	}
	return (grid);
}

int		count_tetri(t_tetri *tetri)
{
	int i;

	i = 0;
	while (tetri[i].alpha)
		i++;
	return (i);
}
	
int		right_grid(int nb)
{
	int size;

	size = 2;
	while (size * size < nb)
		size++;
	return (size);
}
