/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_ta_mere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:24:49 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/16 15:02:24 by psentilh         ###   ########.fr       */
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
	{
		printf("\nSUCCESS\n");
		return (SUCCESS);
	}
	while (try_pos(grid, &tetri[index++], tp = new_point(x, y)) == FAILURE)
	{
		printf("\nFAIL POS\n");
		if (index < 0)
		{
			printf("index < 0\n");
			return (FAILURE);
		}
		printf("Erasing...\n");
		tetri_rm(grid, &tetri[index -= 2]);
		printf("new index = %d\n", tetri[index].index);
		if ((np = new_pos(grid, &tetri[index], new_point(x, ++y))) == NULL)
		{
			y = 0;
			if (index < 0)
			{
				printf("Return FAIL\n");
				return (FAILURE);
			}
			printf("np.x = %d & np.y = %d\n", np->x, np->y);
			printf("\nBACKTRACK\n");
			return (backtracking(grid, &tetri[--index], x, y));
		}
	}
	if ((backtracking(grid, &tetri[index++], x, y)) == FAILURE)
		return (FAILURE);
	printf("\nFake Success\n");
	return (SUCCESS);
}
