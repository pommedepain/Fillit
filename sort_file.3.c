/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file.3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:57:59 by cfauvell          #+#    #+#             */
/*   Updated: 2019/01/10 18:14:27 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Handle the 3 tetriminos who don't work
** normally
*/

char	**particular_T(void)
{
	char *clear;
	char **final;

	clear = ".#..###.........";
	final = tab_filling(clear);
	return (final);
}

char	**particular_T2(void)
{
	char *clear;
	char **final;

	clear = ".#..##...#......";
	final = tab_filling(clear);
	return (final);
}

char	**particular_L(void)
{
	char *clear;
	char **final;

	clear = "..#.###.........";
	final = tab_filling(clear);
	return (final);
}
