/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:00:54 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/29 21:34:44 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tetri	*new_tetri(t_tetri *tetri, char **pos, int w, int h, char alpha, int index)
{
	tetri[index].piece = pos;
	printf("newtetri index = %d\n", index);
	tetri[index].w = w;
	tetri[index].h = h;
	tetri[index].alpha = alpha;
	printf("newtetri alpha = %c\n", tetri->alpha);
	tetri[index].index = index + 1;
	return (tetri/*[index]*/);
}

void	min_max(char *str, t_point *min, t_point *max)
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

t_tetri	*get_piece(t_tetri *tetri, char *buff, char alpha, int index)
{
	t_point *min;
	t_point *max;
	char	**pos;
	int		i;

	min = new_point(3, 3);
	max = new_point(0, 0);
	min_max(buff, min, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], buff + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	tetri = new_tetri(tetri, pos, max->x - min->x + 1, max->y - min->y + 1, alpha, index);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetri/*[index]*/);
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
		//printf("ici 2\n");
		if (i % 5 < 4)
		{
			//printf("ici 3\n");
			if (!(str[i] == '#' || str[i] == '.'))
			{
				//printf("return 1\n");
				return (1);
			}
			if (str[i] == '#' && ++blocs > 4)
			{
				//printf("return 2\n");
				return (2);
			}
		}
		else if (str[i] != '\n')
		{
			//printf("return 3\n");
			return (3);
		}
		i++;
	}
	if (count == 21 && str[20] != '\n')
	{
		//printf("return 4\n");
		return (4);
	}
	if (!check_connection(str))
	{
		//printf("return 5\n");
		return (5);
	}
	//printf("return 0\n");
	return (0);
}

/*int		comparison_function(t_tetri *tetri, int index)
{

}*/

t_tetri	*read_tetri(t_tetri *tetri, int fd, int index)
{
	char 	*buff;
	char	alpha;
	int		count;
	//t_tetri	*tetri;
	//int		index;

	alpha = 'A';
	buff = ft_strnew(21);
	//tetri = NULL;
	//index = 0;
	while ((count = read(fd, buff, 21)) >= 20)
	{
		tetri = (t_tetri *)malloc(sizeof(t_tetri) * 26);
		// quand je veux index++, tout bug ! trouver alternative ou diviser en 2 variables 
		if ((check_counts(buff, count)) != 0 || (tetri = get_piece(tetri, buff, alpha++, index)) == NULL)
		{
			ft_memdel((void **)&buff);
			return (free_tetri(tetri, index));
		}
		printf("index read = %d\n", tetri->index);
		//tetri = (t_tetri *)malloc(sizeof(t_tetri) * 26);
	}
	ft_memdel((void **)&buff);
	//printf("count = %d\n", count);
	if (count != 0)
		return (free_tetri(tetri, index));	
	return (tetri);
}

// verifier de bien envoyer tetri.index dans les params de fonctions et dans leur prototypage pour garder la continuité de la valeurx
