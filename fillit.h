/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:38:21 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/30 16:09:32 by pommedepin       ###   ########.fr       */
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
int		sort_tetri(char *str, t_tetri *test, int i);
t_tetri	*read_tetri(t_tetri *tetri, int fd/*, int index*/);
t_tetri	*get_piece(t_tetri *tetri, char *buff, char alpha/*, int index*/);
int		check_connection(char *str);
int		check_counts(char *str, int count);
void	min_max(char *str, t_point *min, t_point *max);

/*
** Grid :
*/
int		right_grid(int nb);
int		count_tetri(t_tetri *tetri);
t_grid	*init_grid(int size);
void	print_grid(t_grid *grid);
void	free_grid(t_grid *grid);
int		tetri_count(t_tetri *tetri);

/*
** Resolution :
*/
t_grid	*solve_grid(t_tetri *tetri);
int		backtracking(t_tetri *tetri, t_grid *grid, int index);
void	place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c, int index);
int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y, int index);
t_point	*new_point(int x, int y);
//t_tetri	*tetri_init(t_tetri *tetri, int h, int w);

/*
** Extra functions :
*/
t_tetri	*free_tetri(t_tetri *tetri/*, int index*/);
t_tetri	*new_tetri(t_tetri *tetri, char **pos, int w, int h, char alpha/*, int index*/);

#endif
