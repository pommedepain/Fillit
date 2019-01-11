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

/*
** Sort file 1 :
*/

char	*read_all_file(int fd, char *buff);
int		sort_tetri(char *str, t_tetri *test, int i);
t_tetri	*put_in_struct(t_tetri *test, int fd, int index);

/*
** Sort file 2 :
*/

char	*clear_string1(char *tab);
char	*clear_string2(char *tab);
char	**tab_filling(char *tab);
int		sort_particular_case(char *tmp2, t_tetri *test, int i);

/*
** Sort file 3 :
*/

char	**particular_T(void);
char	**particular_T2(void);
char	**particular_L(void);

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
int		choose_place_grid(t_tetri *tetri, t_grid *grid, int x, int y);
void	place_piece(t_tetri *tetri, t_grid *grid, int x, int y, char c);
int		new_pos(t_grid *grid, t_tetri *tetri, int x, int y);
int		backtracking(t_grid *grid, t_tetri *tetri, int x, int y);
t_grid	*solve_grid(t_tetri *tetri);

/*
** free_tetri :
*/
void	free_all(t_tetri *test);
t_tetri	*free_tetri(t_tetri *tetri);

#endif
