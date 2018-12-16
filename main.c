/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:53:12 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/16 22:47:30 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	t_tetri	*test;
	t_grid	*grid;
	int fd;
	int i;
	int index;

	i = 0;
	index = 0;
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
	if ((fd = open (av[1],  O_RDONLY) == 0))
	{
		ft_putstr("The input file is empty. Please try again with a valid one !");
		return (-1);
	}
	if (!(test = (t_tetri*)malloc(sizeof(t_tetri) * 26)))
		return (-1);
	while (i < 5)
	{
		if(!(sort_tetri(fd, test, index)))
		{
			ft_putstr("You wanker... 😑\nYou couldn't even find a valid file ? 👊 💢\n");
			return (-1);
		}
		ft_putstr("\n");
		if (!(check_tetri(test[index].piece)))
		{
			ft_putstr("NEED VALID TETRIMINOS 🙌\n");
			return (-1);
		}
		ft_print_words_tables(test[index].piece);
		index += 1;
		test->index = index;
		ft_putnbr(test->index);
		ft_putstr("\n");
		i++;
	}
	grid = solve_grid(test/*, grid*/);
	print_grid(grid);
	free_grid(grid);
	ft_putstr("\n");
	close (fd);
	return (0);
}
