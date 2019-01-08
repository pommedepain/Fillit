/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:38:21 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/08 14:39:01 by pommedepin       ###   ########.fr       */
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
	//int		end;
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
t_tetri	*put_in_struct(t_tetri *test, int fd, int index);
char	*read_all_file(int fd, char *buff);
int		check_tetri(char **tab);
int		ft_check_pattern(char **tab, int y, int x, int count);
int		sort_tetri(char *str, t_tetri *test, int i);
t_tetri	*read_tetri(t_tetri *tetri, int fd/*, int index*/);
t_tetri	*get_piece(t_tetri *tetri, char *buff, char alpha/*, int index*/);
int		check_connection(char *str);
int		check_counts(char *str, int count);
void	min_max(t_tetri *tetri, t_point *min, t_point *max, int index);
t_tetri	*tetri_h_w(t_tetri *tetri);

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
int		backtracking(t_grid *grid, t_tetri *tetri/*, int index*/);
void	place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c, int index);
int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y, int index);
t_point	*new_point(int x, int y);

/*
** Extra functions :
*/
t_tetri	*free_tetri(t_tetri *tetri);
t_tetri	*new_tetri(t_tetri *tetri, char **pos, int w, int h, char alpha/*, int index*/);
void	free_all(t_tetri *test);

#endif
