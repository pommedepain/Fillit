/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:53:12 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/12 18:49:58 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_grid	*grid;
	t_tetri	*tetri;
	int		index;
	int		fd;

	index = 0;
	tetri = NULL;
	grid = NULL;
	if (ac != 2)
	{
		ft_putstr("usage : ./fillit file_descriptor\n");
		return (-1);
	}
	fd = open(av[1],  O_RDONLY);
	if (!(tetri = put_in_struct(tetri, fd, index)))
	{
		close(fd);
		ft_putstr("error\n");
		return (-1);
	}
	if ((tetri_h_w(tetri) == NULL))
		return (-1);
	while (tetri[index].piece)
	{
		ft_print_words_tables(tetri[index].piece);
		ft_putnbr(tetri[index].index);
		ft_putchar('\n');
		ft_putchar(tetri[index].alpha);
		ft_putchar('\n');
		ft_putnbr(tetri[index].h);
		ft_putchar('\n');
		ft_putnbr(tetri[index].w);
		ft_putstr("\n\n");
		index++;
	}
	grid = solve_grid(tetri);
	print_grid(grid);
	free_grid(grid);
	free_all(tetri);
	close(fd);
	return (0);
}
