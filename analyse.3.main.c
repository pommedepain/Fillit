/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.3.main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:15:40 by cfauvell          #+#    #+#             */
/*   Updated: 2019/01/05 18:34:42 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	ft_strdel(&buff);
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
/*Permet de voir si la forme du tetriminos est valable*/
int		ft_check_pattern(char **tab, int y, int x, int count)
{
	y != 0 && tab[y - 1][x] == '#' ? count++ : 0;
	x != 0 && tab[y][x - 1] == '#' ? count++ : 0;
	x != 3 && tab[y][x + 1] == '#' ? count++ : 0;
	y != 3 && tab[y + 1][x] == '#' ? count++ : 0;
	return (count);
}

/*Permet de verifier le tetriminos*/
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
t_tetri         *ft_put_in_struct(t_tetri *test, int fd)
{
    static char	*final;
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
    if (!(test = (t_tetri *)malloc(sizeof(t_tetri) * (len + 1))))
        return (NULL);
    while (len--)
    {
        if(!(sort_tetri(final, test, index)))
            return(NULL);
        if (!(check_tetri(test[index].piece)))
            return(NULL);
        index++;
        test[index - 1].index = index;
        test[index - 1].alpha = 64 + index;
    }
    test[index].piece = NULL;
	return (test);
}

/*t_tetri	*tetri_init(t_tetri *tetri, int h, int w)
{
	tetri = (t_tetri *)malloc(sizeof(t_tetri));
	tetri->h = h;
	tetri->w = w;
	return (tetri);
}*/

void	min_max(t_tetri *tetri, t_point *min, t_point *max, int index)
{
	int		i;
	int		j;
	char	*str;

	str = ft_strnew(21);
	i = 0;
	while (i < 4)
	{
		str = ft_strcat(str, tetri[index].piece[i]);
		str = ft_strcat(str, "\n");
		i++;
	}
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
	free(str);
}

t_tetri	*tetri_h_w(t_tetri *tetri)
{
	t_point *min;
	t_point *max;
	int		index;

	index = tetri_count(tetri) - 1;
	while (index != -1)
	{
		min = new_point(3, 3);
		max = new_point(0, 0);
		min_max(tetri, min, max, index);
		//tetri[index].h = max->x - min->x + 1;
		//tetri[index].w = max->y - min->y + 1;
		tetri[index].h = max->y - min->y + 1;
		tetri[index].w = max->x - min->x + 1;
		ft_memdel((void **)&min);
		ft_memdel((void **)&max);
		index--;
	}
	return (tetri);
}

int		main(int ac, char **av)
{
	int			fd;
	t_tetri		*test;
	int index;
	t_grid	*grid;

	grid = NULL;
	test = NULL;
	if (ac != 2)
		return (-1);
	fd = open(av[1],  O_RDONLY);
	if (!(test = ft_put_in_struct(test, fd)))
		return (-1);
	if ((tetri_h_w(test) == NULL))
		return (-1);
	while (index != 4)
	{
		ft_print_words_tables(test[index].piece);
		ft_putnbr(test[index].index);
		ft_putchar('\n');
		ft_putchar(test[index].alpha);
		ft_putstr("\n\n");
		index++;
	}
	grid = solve_grid(test);
	//printf("ici\n");
	print_grid(grid);
	free_grid(grid);
	free_all(test);
	close (fd);
	return (1);
}
