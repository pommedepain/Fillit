/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:11:00 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/11 13:13:13 by cfauvell         ###   ########.fr       */
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

/*
** 
*/
t_grid	*init_grid(int size)// peut-etre à simplifier avec memset
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
	//ft_print_words_tables(grid->tab);
	return (grid);
}

/*
** On décrémente alpha car quand il est envoyé dans la fonction, il est au max du nb de tetris
*/
int			tetri_count(t_tetri *tetri)
{
	/*int index;

	index = 1;
	while (tetri->alpha != 'A')
	{
		tetri->alpha--;
		index++;
	}
	return(index);*/

	int	i;

	i = 0;
	while (tetri[i].piece)
		i++;
	return (i);
}

int			right_grid(int nb)
{
	int size;

	size = 1;
	while (size * size < nb)
		size++;
	return (size);
}
