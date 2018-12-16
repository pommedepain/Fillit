/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:38:21 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/16 21:58:12 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 600

typedef	struct		s_tetri
{
	char	**piece;
	char	alpha;
	int		index;
	int		h;
	int		w;
}					t_tetri;

typedef struct		s_grid
{
	char	**tab;
	int		size;
}					t_grid;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

/*
** Parsing :
*/
int		check_tetri(char **tab);
int		ft_check_pattern(char **tab, int y, int x, int count);
int		sort_tetri(int fd, t_tetri *test, int i);
char	*read_all_file(int fd, char *buff, int *ret);

/*
** Grid :
*/
int		right_grid(int nb);
int		count_tetri(t_tetri *tetri);
t_grid	*init_grid(int size);
void	print_grid(t_grid *grid);
void	free_grid(t_grid *grid);

/*
** Resolution :
*/
t_grid	*solve_grid(t_tetri *tetri, t_grid *grid);
int		backtracking(t_tetri *tetri, t_grid *grid, int index);
void	place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c, int index);
int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y, int index);
t_point	*new_point(int x, int y);

#endif
