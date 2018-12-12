/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:02:01 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/07 14:20:47 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_next_line_valid(int fd, t_tetri tetri)
{
	char	*line;

	line = NULL;
	get_next_line(fd, &line);
	if (line && line[0])
	{
		//ft_structdel(tetri);
		return (-1);
	}
	return (0);
}

int		ft_fd_into_struct(t_tetri *tetri, int fd)
{
	int		i;
	int		j;
	int		ret;
	char	*line;

	i = 0;
	line = NULL;
	if (!(tetri = (t_tetri)malloc(sizeof(t_tetri) * 26)))
		return (-1);
	while (tetri[i])
	{
		j = 0;
		if (!(tetri[i].piece = (char **)malloc(sizeof(char) * 5)))
		{
			//ft_structdel(tetri);
			return (-1);
		}
		tetri[i].piece[5] = 0;
		while (tetri[i].piece)
			ret = get_next_line(fd, tetri[i].piece[j++]);
		i++;
		ft_is_next_line_valid(fd, tetri);
	}
}
