/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_phil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:00:54 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/10 18:13:25 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fake.fillit.h"
#include <stdio.h>

t_tetri	*new_tetri(t_tetri *tetri/*, char **pos*/, int w, int h, char alpha)
{
	//char	**temp;

	//temp = pos;
	//tetri->piece = pos;
	tetri->w = w;
	tetri->h = h;
	tetri->alpha = alpha;
	//free(temp);
	return (tetri);
}

void	min_max(t_tetri *tetri, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i/ 5 < min->y)
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
}

t_tetri	*get_piece(t_tetri *tetri, char *buff, char alpha)
{
	t_point *min;
	t_point *max;
	//char	**pos;
	int		i;

	min = new_point(3, 3);
	max = new_point(0, 0);
	min_max(buff, min, max);
	//tetri->piece = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = ft_word_count(buff, '\n');
	tetri->piece = NULL;
	tetri->piece = (char **)malloc(sizeof(char *) * (i + 1));
	tetri->piece[i] = 0;
	ft_letter_count(tetri->piece, buff, '\n');
	ft_tab_filling(tetri->piece, buff, '\n');
	//tetri->piece = strsplit(buff, '\n');
	printf("ici\n");
	//i = 0;
	/*while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], buff + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}*/
	tetri = new_tetri(tetri/*, pos*/, max->x - min->x + 1, max->y - min->y + 1, alpha);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri);
}

int		check_connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int		check_counts(char *str, int count)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (!check_connection(str))
		return (5);
	return (0);
}

t_tetri	*read_tetri(t_tetri *tetri, int fd)
{
	char 	*buff;
	char	alpha;
	int		count;

	alpha = 'A';
	buff = ft_strnew(21);
	while ((count = read(fd, buff, 21)) >= 20)
	{
		if ((check_counts(buff, count)) != 0 || (tetri = get_piece(tetri, buff, alpha++)) == NULL)
		{
			ft_memdel((void **)&buff);
			return (free_tetri(tetri));
		}
		tetri = (t_tetri *)malloc(sizeof(t_tetri) * 26);
	}
	ft_memdel((void **)&buff);
	if (count != 0)
		return (free_tetri(tetri));
	return (tetri);
}
