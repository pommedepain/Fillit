/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_backtracking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:59:41 by pommedepin        #+#    #+#             */
/*   Updated: 2019/01/12 14:59:58 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pendant qu'on parcourt la grille, on vérifie s'il y a une place pour le tetri en cours
** Si oui, et que tous les tetris sont placés, on renvoit 1.
** Sinon on place ce tetri et on passe au suivant.
** Si on a parcourut tous les tetris sans avoir reussi à tous les placer, on renvoie 0 pour rappeler la fonction avec une grille plus grande.
*/

int			backtracking(t_grid *grid, t_tetri *tetri)
{
	int y;
	int x;
	int index;

	y = 0;
	index = 0;
	while (y < (grid->size - tetri[index].h + 1))
	{
		if (tetri->piece == NULL)
			return (1);
		x = 0;
		while (x < (grid->size - tetri[index].w + 1))
		{
			if (choose_place_grid(&tetri[index], grid, x, y))
			{
				if (backtracking(grid, &tetri[++index]))
					return (1);
				else
					place_piece(&tetri[index], grid, new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}
