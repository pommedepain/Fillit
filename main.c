/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:53:12 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/22 17:06:03 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_end_of_prog(t_grid *grid, t_tetri *tetri)
{
	print_grid(grid);
	free_grid(grid);
	free_tetri(tetri);
}

int			ft_beginning_of_prog(int ac)
{
	if (ac != 2)
	{
		ft_putstr("usage : ./fillit file_descriptor\n");
		return (-1);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_grid	*grid;
	t_tetri	*tetri;
	int		index;
	int		fd;

	index = 0;
	tetri = NULL;
	grid = NULL;
	fd = 0;
	if (ft_beginning_of_prog(ac) == -1)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if ((!(tetri = put_in_struct(tetri, fd, index))))
	{
		close(fd);
		ft_putstr("error\n");
		return (-1);
	}
	if (tetri_h_w(tetri) == NULL)
		return (-1);
	grid = solve_grid(tetri);
	ft_end_of_prog(grid, tetri);
	close(fd);
	return (0);
}
