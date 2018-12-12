/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:38:21 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/11 14:15:09 by psentilh         ###   ########.fr       */
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

#endif
