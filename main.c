/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:53:12 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/10 16:56:34 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*int		main(int ac, char **av)
{
	int fd;
	t_tetri *tetri;

	if (ac < 2)
		ft_putstr("Insufficient number of arguments.\n Please select a file to solve. 🙏 \n");
		//ft_putstr("Are you braindamaged ? 🤦\nYou forgot the file dumbass ! 👏\n");
	else if (ac >= 3)
		ft_putstr("Excessive number of arguments.\n Please, select a single file to solve. 💥 || 🙅 \n");
		//ft_putstr("One file at a time arsehole.\nNo chritmas present for you ! 🎅 🖕 🎁 💥\n");
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (sort_tetri(fd, tetri, i))
			solve_grid(tetri);
		else
			ft_putstr("The selected file is not valid. 👎 \n");
			//ft_putstr("You wanker... 😑\nYou couldn't even find a valid file ? 👊 💢\n");
    	close(fd);
	}
	return (0);
}*/

int		main(int ac, char **av)
{
	t_grid	*grid;
	t_tetri	*tetri;
	int		index;
	int		fd;

	index = 0;
	tetri = NULL;
	grid = NULL;
	if (ac < 2)
	{
		ft_putstr("Are you braindamaged ? 🤦\nYou forgot the file dumbass ! 👏\n");
		return (-1);
	}
	if (ac >= 3)
	{
		ft_putstr("One file at a time arsehole.\nNo chritmas present for you ! 🎅 🖕 🎁 💥\n");
		return (-1);
	}
	fd = open(av[1],  O_RDONLY);
	if (!(tetri = put_in_struct(tetri, fd, index)))
	{
		close(fd);
		ft_putstr("You wanker... 😑\nYou couldn't even find a valid file ? 👊 💢\n");
		return (-1);
	}
	if ((tetri_h_w(tetri) == NULL))
		return (-1);
	while (index != 4)
	{
		ft_print_words_tables(tetri[index].piece);
		ft_putnbr(tetri[index].index);
		ft_putchar('\n');
		ft_putchar(tetri[index].alpha);
		ft_putchar('\n');
		ft_putnbr(tetri[index].h);
		ft_putchar('\n');
		ft_putnbr(tetri[index].w);
		/*ft_putchar('\n');
		ft_putnbr(tetri[index].end);*/
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
