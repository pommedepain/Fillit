/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.3.main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:15:40 by cfauvell          #+#    #+#             */
/*   Updated: 2018/12/21 18:11:27 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (buff[0] == '\n' || ft_strlen(buff) > 545 || (ft_strlen(buff) + 1) % 21 != 0)
		return (NULL);
	ft_strdel(&tmp2);
	return (buff);
}

//Fonction qui permet de repartir le fichier en t_tetri *
int		sort_tetri(char *str, t_tetri *test, int i)
{
	char		*tmp;

	if ((tmp = ft_strstr(str, "\n\n")) != NULL)
		*tmp = '\0';
	if (!(test[i].piece = ft_strsplit(str, '\n')))
		return (-1);
	ft_memmove(str, tmp + 2, ft_strlen(tmp + 2));
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

//Fonction qui met toute les valeurs dans le pointeur sur structure
t_tetri		*ft_put_in_struct(t_tetri *test, int fd)
{
	static char *final;
	int			index;
	int			ret;
	int			len;

	index = 0;
	ret = 0;
	if (!(final = ft_strnew(0)))
		return (NULL);
	if (!(final = read_all_file(fd, final, &ret)))
		return (NULL);
	len = (ft_strlen(final) + 1) / 21;
	if (!(test = (t_tetri*)malloc(sizeof(t_tetri) * len)))
		return (NULL);
	while (len)
	{
		if(!(sort_tetri(final, test, index)))
		{
			free_all(test, index);
			return(NULL);
		}
		if (!(check_tetri(test[index].piece)))
		{
			free_all(test, index);
			return(NULL);
		}
		index++;
		test[index - 1].index = index;
		test[index - 1].alpha = 64 + index;
		len --;
	}
	return (test);
}

int		main(int ac, char **av)
{
	int			fd;
	t_tetri		*test;
	//t_grid		*grid;
	int index;

	if (ac != 2)
		return (-1);
	fd = open(av[1],  O_RDONLY);
	if (!(test = (t_tetri*)malloc(sizeof(t_tetri))))
		return (-1);
	if (!(test = ft_put_in_struct(test, fd)))
		return (-1);
	index = test->index;
	//grid = solve_grid(test);
	//print_grid(grid);
	//free_grid(grid);
	ft_print_words_tables(test[0].piece);
	ft_putnbr(test[0].index);
	ft_putchar('\n');
	ft_putchar(test[0].alpha);
	ft_putchar('\n');
	free_all(test, index);
	close (fd);
	return (1);
}
