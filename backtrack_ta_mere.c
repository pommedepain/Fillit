/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_ta_mere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:24:49 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/15 15:18:25 by psentilh         ###   ########.fr       */
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
	while ((try_pos(grid, &tetri[index], tp = new_point(x, y))) == FAILURE)
	{
		printf("\nERASE\n");
		tetri_rm(grid, &tetri[--index]);
		printf("1 erase x = %d & y = %d\n\n", x, y);
		// si tu arrives a placer ailleurs le tetri actuel
		if ((np = new_pos(grid, &tetri[index], new_point(x, ++y))) != NULL)
		{
			y = 0;
			printf("x = %d & y = %d\n", x, y);
			printf("tp->x = %d & tp->y = %d\n", tp->x, tp->y);
			// mais que tu n'arrives toujours pas a placer le suivant
			if ((try_pos(grid, &tetri[++index], new_point(x, y))) == FAILURE)
			{
				if (index < 0)
				{
					printf("\nSUCESS index == 0\n");
					return (SUCCESS);
				}
				printf("index BT = %d\n", tetri->index);
				printf("\nERASE 2\n");
				if ((backtracking(grid, &tetri[--index], x, ++y) != SUCCESS))
				{
					printf("\nSUCCESS tous tetris placés\n");
					return (SUCCESS);
				}
				/*tetri_rm(grid, &tetri[--index]);
				np->y++;
				printf("np->y = %d\n", np->y);
				if (try_pos(grid, &tetri[index++], np) == FAILURE)
					return (FAILURE);*/
			}
			else
			{
				printf("\nSUCCESS next tetri placé\n");
				return (SUCCESS);
			}
		}
		else
		{
			printf("\nFAIL impossible de placer le tetri ailleurs\n");
			return (FAILURE);
		}
		if (tetri->index < 0)
			return (FAILURE);
	}
	index++;
	printf("\nBACKTRACK\n\n");
	while ((backtracking(grid, &tetri[index], x, y)) == FAILURE)
	{
		printf("ERROR\n\n");
		return (FAILURE);
	}
	printf("ici\n");
	return (SUCCESS);
}
