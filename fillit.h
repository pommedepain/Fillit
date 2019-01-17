/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:40 by psentilh          #+#    #+#             */
/*   Updated: 2019/01/10 18:11:00 by psentilh         ###   ########.fr       */
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
# define SUCCESS 1
# define ERROR -1
# define FAILURE 0

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

int		ft_check_pattern(char **tab, int y, int x, int count);
int		check_tetri(char **tab);
void	min_max(t_tetri *tetri, t_point *min, t_point *max, int index);
t_tetri	*tetri_h_w(t_tetri *tetri);
char	**particular_s2(void);

/*
** Sort file 1 :
*/

char	*read_all_file(int fd, char *buff);
int		sort_tetri(char *str, t_tetri *test, int i);
int		sort_tetri1(char *str, t_tetri *test, int index);
t_tetri	*for_one_tetri(t_tetri *test, char *final, int index);
t_tetri	*put_in_struct(t_tetri *test, int fd, int index);

/*
** Sort file 2 :
*/

char	*clear_string1(char *tab);
char	*clear_string2(char *tab);
char	**tab_filling(char *tab);
int		sort_particular_case(char *tmp2, t_tetri *test, int i);
int		hash_count(char *tab);

/*
** Sort file 3 :
*/

char	**particular_t1(void);
char	**particular_t2(void);
char	**particular_l(void);
char	**particular_l2(void);
char	**particular_s(void);

/*
** Grid :
*/

int		right_grid(int nb);
t_grid	*init_grid(int size);
void	print_grid(t_grid *grid);
void	free_grid(t_grid *grid);
int		tetri_count(t_tetri *tetri);

/*
** Backtracking :
*/

t_point	*new_point(int x, int y);
t_point	*choose_place_grid(t_tetri *tetri, t_grid *grid, t_point *point);
t_grid	*place_piece(t_tetri *tetri, t_grid *grid, t_point *point, char c);
int		try_pos(t_grid *grid, t_tetri *tetri, t_point *point);
t_point	*new_pos(t_grid *grid, t_point *point);
int		backtracking(t_grid *grid, t_tetri *tetri, t_point *np);
t_grid	*solve_grid(t_tetri *tetri);
void	tetri_rm(t_grid *grid, t_tetri *tetri);

/*
** free_tetri :
*/
void	free_all(t_tetri *test);
t_tetri	*free_tetri(t_tetri *tetri);

#endif
