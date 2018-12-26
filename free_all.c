/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:52:24 by cfauvell          #+#    #+#             */
/*   Updated: 2018/12/21 21:10:44 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*void	free_all(t_tetri *test)
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
	free(test);
}*/

void	free_tetri(t_tetri *tetri, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		ft_memdel((void **)&(tetri[index].piece[i]));
		i++;
	}
	ft_memdel((void **)&(tetri[index].piece));
	ft_memdel((void **)&tetri);
}
