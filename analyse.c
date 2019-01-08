/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:00:54 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/08 14:10:27 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** Get the file to a string
*/

char	*read_all_file(int fd, char *buff)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;
	int		ret;

	ret = 0;
	ret = read(fd, tmp, BUFF_SIZE);
	tmp[ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (NULL);
	if (buff[0] == '\n' || ft_strlen(buff) > 545 ||
		(ft_strlen(buff) + 1) % 21 != 0)
	{
		free(buff);
		free(tmp2);
		return (NULL);
	}
	free(tmp2);
	return (buff);
}

/*
** Divide the string into a char array
*/

int		sort_tetri(char *str, t_tetri *test, int i)
{
	char	*tmp;

	if ((tmp = ft_strstr(str, "\n\n")) != NULL)
		*tmp = '\0';
	if (!(test[i].piece = ft_strsplit(str, '\n')))
		return (-1);
	ft_memmove(str, tmp + 2, ft_strlen(tmp + 2));
	return (1);
}

/*
** Check tetriminos (secondary function)
*/

int		ft_check_pattern(char **tab, int y, int x, int count)
{
	y != 0 && tab[y - 1][x] == '#' ? count++ : 0;
	x != 0 && tab[y][x - 1] == '#' ? count++ : 0;
	x != 3 && tab[y][x + 1] == '#' ? count++ : 0;
	y != 3 && tab[y + 1][x] == '#' ? count++ : 0;
	return (count);
}

/*
** Check tetriminos (principal function)
*/

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
	return (y == 4 && hash == 4 && count >= 6);
}

/*
** Convert the file to a structure table
** (if valid)
*/

t_tetri	*put_in_struct(t_tetri *test, int fd, int index)
{
	static char	*final;
	int			len;

	if (!(final = ft_strnew(0)))
		return (NULL);
	if (!(final = read_all_file(fd, final)))
		return (NULL);
	len = (ft_strlen(final) + 1) / 21;
	if (!(test = (t_tetri *)malloc(sizeof(t_tetri) * (len + 1))))
		return (NULL);
	while (len--)
	{
		if (!(sort_tetri(final, test, index)))
			return (NULL);
		if (!(check_tetri(test[index++].piece)))
		{
			free_all(test);
			return (NULL);
		}
		test[index - 1].index = index;
		test[index - 1].alpha = 64 + index;
		//test[index - 1].end = 1;
	}
	//test[index - 1].end = 0;
	test[index].piece = NULL;
	return (test);
}

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
