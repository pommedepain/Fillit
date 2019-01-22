/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:46:00 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/22 14:46:25 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			stop_condition(t_tetri *tetri, t_point *np)
{
	if (tetri->piece == NULL)
	{
		ft_memdel((void **)&np);
		return (SUCCESS);
	}
	if (np == NULL)
		return (FAILURE);
	return (-1);
}

void		free_point(t_point *point)
{
	static int	count = 0;

	count++;
	if (count != 1)
		ft_memdel((void **)&point);
}
