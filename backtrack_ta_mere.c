/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_ta_mere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:24:49 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/15 16:20:15 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				backtracking(t_grid *grid, t_tetri *tetri, int x, int y)
{
	int		index;
	t_point *tp;
	t_point	*np;

	index = 0;
	tp = NULL;
	np = NULL;
	printf("index tetri = %d\n", tetri[index].index);
	if (tetri[index].piece == NULL)
			return (SUCCESS);
	/*if (index < 0)
		return (FAILURE);*/
	if (try_pos(grid, &tetri[index], tp = new_point(x, y++)) == FAILURE)
		return (tetri_rm(grid, &tetri[--index]) && backtracking(grid, &tetri[++index], x, y));
	return (SUCCESS);
}
