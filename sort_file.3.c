/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file.3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:57:59 by cfauvell          #+#    #+#             */
/*   Updated: 2019/01/14 17:27:16 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Handle the 5 tetriminos who don't work
** normally
*/

char	**particular_t1(void)
{
	char *clear;
	char **final;

	clear = ".#..###.........";
	final = tab_filling(clear);
	return (final);
}

char	**particular_t2(void)
{
	char *clear;
	char **final;

	clear = ".#..##...#......";
	final = tab_filling(clear);
	return (final);
}

char	**particular_l(void)
{
	char *clear;
	char **final;

	clear = "..#.###.........";
	final = tab_filling(clear);
	return (final);
}

char	**particular_s(void)
{
	char *clear;
	char **final;

	clear = ".##.##..........";
	final = tab_filling(clear);
	return (final);
}

char	**particular_s2(void)
{
	char *clear;
	char **final;

	clear = ".#..##..#.......";
	final = tab_filling(clear);
	return (final);
}
