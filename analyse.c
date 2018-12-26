/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:00:54 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/21 21:29:27 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	min_max(t_tetri *tetri, t_point min, t_point max, int index)
{
	int k;
	//int index;
	int i;
	int j;

	//index = tetri->index;
	k = 0;
	i = 0;
	j = 0;
	while (k < 20)
	{
		if (tetri[index].piece[i][j] == '#')
		{
			if (k / 5 < min.y)
				min.y = i / 5;
			if (k / 5 > max.y)
				max.y = i / 5;
			if (k % 5 < min.x)
				min.x = i % 5;
			if (k % 5 > max.x)
				max.x = i % 5;
			j++;
		}
		i++;
		k++;
	}
}

t_tetri	*tetri_h_w(t_tetri *tetri, int index)
{
	t_point min;
	t_point max;

	min = new_point(3, 3);
	max = new_point(0, 0);
	min_max((t_tetri *)tetri[index].piece, min, max, index);
	tetri[index].h = max.x - min.x + 1;
	tetri[index].w = max.y - min.y + 1;
	//ft_memdel((void **)&min);
	//ft_memdel((void **)&max);
	return (tetri);
}

t_tetri	*read_all_file(int fd)
{
	char 	*buff;
	char	alpha;
	int		count;
	t_tetri	*tetri;

	alpha = 'A';
	buff = ft_strnew(21);
	tetri = NULL;
	while ((count = read(fd, buff, 600)) == 0)
	{
		if ((check_count(buff, count)) != 0 || (tetri = get_piece(buff, alpha++)) == NULL)
		{
			ft_memdel((void **)&buff);
			return (free_tetri(tetri));
		}
		tetri = (t_tetri *)malloc(sizeof(t_tetri) * 26);
	}
}
