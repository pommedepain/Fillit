/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:52:24 by cfauvell          #+#    #+#             */
/*   Updated: 2018/12/27 16:05:30 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	free_all(t_tetri *test)
{
	int i;
	int y;

	y = 0;
	while(test[y].piece != '\0')
	{
		i = 0;
		while(test[y].piece[i] != '\0')
		{
			free(test[y].piece[i]);
			i++;
		}
		free(test[y].piece);
		y++;
	}
	ft_memdel((void **)&test);
	free(test);
}

t_tetri	*free_tetri(t_tetri *tetri)
{
	/*int i;

	i = 0;
	while (i < index || i <= 4)
	{
		ft_memdel((void **)&(tetri[index].piece[i]));
		ft_memdel((void **)&(tetri[index].alpha));
		ft_memdel((void **)&(tetri[index].index));
		ft_memdel((void **)&(tetri[index].h));
		ft_memdel((void **)&(tetri[index].w));
		i++;
	}
	ft_memdel((void **)&(tetri[index].piece));
	ft_memdel((void **)&tetri);
	return (tetri);*/
	int i = 26;
	while (i)
	{
		ft_memdel((void **)&tetri);
		i--;
	}
	ft_memdel((void **)&tetri);
	//tetri = NULL;
	return (tetri);
}
