/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:30:07 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/14 15:21:57 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

//Fonction qui recupère tout le fichier d'un coup
char	*read_all_file(int fd, char *buff, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;

	*ret = read(fd, tmp, BUFF_SIZE);
	tmp[*ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (NULL);
	if (buff[0] == '\n' || ft_strlen(buff) > 545)
		return (NULL);
	ft_strdel(&tmp2);
	return (buff);
}

//Fonction qui permet de repartir le fichier en t_tetri *
int		sort_tetri(int fd, t_tetri *test, int i)
{
	static char	*final;
	char		*tmp;
	int			ret;

	ret = 0;
	if (!final && !(final = ft_strnew(0)))
		return (-1);
	if (!(final = read_all_file(fd, final, &ret)))
		return (-1);
	if ((tmp = ft_strstr(final, "\n\n")) != NULL)
		*tmp = '\0';
	if (!(test[i].piece = ft_strsplit(final, '\n')))
		return (-1);
	if ((ft_strlen(final) == 21))
		return (0);
	if (!(ft_memmove(final, tmp + 2, ft_strlen(tmp + 2))))
		return (-1);
	return (1);
}

int		ft_check_pattern(char **tab, int y, int x, int count)
{
	y != 0 && tab[y - 1][x] == '#' ? count++ : 0;
	x != 0 && tab[y][x - 1] == '#' ? count++ : 0;
	x != 3 && tab[y][x + 1] == '#' ? count++ : 0;
	y != 3 && tab[y + 1][x] == '#' ? count++ : 0;
	return (count);
}

/*Permet de tester le tetriminos(sans la reconnaissance des pieces pour
le moment)*/
int		check_tetri(char **tab)
{
	int x;
	int y;
	int hash;
	int count;

	y = -1;
	hash = 0;
	count = 0;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (tab[y][x] != '.' && tab[y][x] != '#')
				return (0);
			if (tab[y][x] == '#')
			{
				hash++;
				count = ft_check_pattern(tab, y, x, count);
			}
		}
		if (x != 4)
			return (0);
	}
	return (y == 4 && hash == 4 && count > 5);
}

int		count_tetri(t_tetri *tetri)
{
	int i;

	i = 0;
	i = tetri->index;
	return (i);
}

int		main(int ac, char **av)
{
	t_tetri	*test;
	int fd;
	int i;
	int index;
	int ret;

	ret = 0;
	i = 0;
	index = 0;
	fd = open (av[1],  O_RDONLY);
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
	if (!(test = (t_tetri*)malloc(sizeof(t_tetri) * 26)))
		return (-1);
	while (i < 4)
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
	ft_putstr("\n");
	ret = count_tetri(test);
	ft_putnbr(ret);
	close (fd);
	return (0);
}
