/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:20:29 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/07 16:32:36 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**increase_tab(char **grid, int h, int w)
{
	while (grid)
	{
		grid[h] += grid[h + 1];
		grid[h][w] += grid [h][w + 1];
	}
	return (grid);
}

void	init_grid(char grid[2][2])
{
	int h;
	int w;

	h = 0;
	while (h < 2)
	{
		w = 0;
		while (w < 2)
		{
			grid[h][w] = 0;
			w++;
		}
		h++;
	}
}

void	fill_grid(t_tetri *tetri, char **grid)
{
	int h;
	int w
	int i;

	init_grid(grid);
	h = 0;
	i = 0;
	while (grid[h])
	{
		w = 0;
		while (tetri[i].piece)
		{
			//if (grid[h][w] tetri[i].piece)
			//	grid[h][w] = tetri.alpha;
			else
			{
				grid = increase_tab(grid, h, w);
			}
			w++;
		}
		h++;
	}
}

void	fillit(int fd)
{
	char grid[2][2];
	int ret;

	ret = 0;
	fill_grid(fd, grid);
	/*if (is_grid_valid(grid) == -1)
	{
		ft_putstr("Error\n");
		return (-1);
	}*/
	process(fd, grid, ret);
	if (ret == 1)
		display(grid);
	else
	{
		ft_putstr("Error\n");
		return (-1);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac < 2 || ac >= 3)
		ft_putstr("Error\n");
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (analyse(fd) == 1)
			fillit(fd);
		else
			ft_putstr("Error\n");
    	close(fd);
	}
	return (0);
}
