/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:53:12 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/12 16:54:48 by psentilh         ###   ########.fr       */
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

int		main(void)
{
	t_tetri	*test;
	int fd;
	int i;

	i = 0;
	fd = open ("test_4.fillit",  O_RDONLY);
	if (!(test = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	while (i < 4)
	{
		if(!(test = sort_tetri(fd, test, i)))
		{
			ft_putstr("NEED VALID FILE 😉\n");
			return (0);
		}
		if (!(check_tetri(test[0].piece)))
		{
			ft_putstr("NEED VALID TETRIMINOS 🙌\n");
			return (0);
		}
		ft_print_words_tables(test[i].piece);
		ft_putstr("\n");
		i++;
		test[i].index = i;
		ft_putnbr(test[0].index);
	}
	ft_putstr("\n");
	close (fd);
}
