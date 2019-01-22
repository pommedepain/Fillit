/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file.1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:52:34 by cfauvell          #+#    #+#             */
/*   Updated: 2019/01/22 12:56:13 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Get the file to a string
*/

char	*read_all_file(int fd, char *buff)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;
	int		ret;

	ret = 0;
	if (fd == -1)
	{
		free(buff);
		return (NULL);
	}
	ret = read(fd, tmp, BUFF_SIZE);
	tmp[ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (NULL);
	if (buff[0] == '\n' || ft_strlen(buff) > 545 ||
		(ft_strlen(buff) + 1) % 21 != 0)
	{
		free(buff);
		free(tmp2);
		return (NULL);
	}
	free(tmp2);
	return (buff);
}

/*
** Divide the string between the different tetriminos and
** put it in a char array
*/

int		sort_tetri(char *str, t_tetri *tetri, int i)
{
	char	*tmp;
	char	*tmp2;

	if ((tmp = ft_strstr(str, "\n\n")) != NULL)
		*tmp = '\0';
	if (ft_strlen(str) != 19)
		return (0);
	tmp2 = ft_strdup(str);
	tmp2 = clear_string1(tmp2);
	if (sort_particular_case(tmp2, tetri, i) == 1)
	{
		ft_memmove(str, tmp + 2, ft_strlen(tmp + 2));
		free(tmp2);
		return (1);
	}
	tmp2 = clear_string2(tmp2);
	if (!(tetri[i].piece = tab_filling(tmp2)))
		return (0);
	ft_memmove(str, tmp + 2, ft_strlen(tmp + 2));
	free(tmp2);
	return (1);
}

/*
** Fill the struct if there is just one tetriminos
*/

t_tetri	*for_one_tetri(t_tetri *tetri, char *final, int index)
{
	if (!(sort_tetri1(final, tetri, index)))
	{
		free_tetri(tetri);
		return (NULL);
	}
	if (!(check_tetri(tetri[0].piece)))
	{
		tetri[1].piece = NULL;
		free_tetri(tetri);
		return (NULL);
	}
	tetri[0].index = 1;
	tetri[0].alpha = 'A';
	tetri[1].piece = NULL;
	return (tetri);
}

/*
** Fill the struct if there is multiple tetriminos
*/

t_tetri	*for_multi_tetri(t_tetri *tetri, char *final, int index)
{
	if (sort_tetri(final, tetri, index) == 0)
	{
		if (index == 0)
			free(tetri);
		else
		{
			tetri[index].piece = NULL;
			free_tetri(tetri);
		}
		return (NULL);
	}
	if (!(check_tetri(tetri[index].piece)))
	{
		tetri[index + 1].piece = NULL;
		free_tetri(tetri);
		return (NULL);
	}
	tetri[index].index = index + 1;
	tetri[index].alpha = 65 + index;
	return (tetri);
}

/*
** Convert the file to a structure table
** (if valid)
*/

t_tetri	*put_in_struct(t_tetri *tetri, int fd, int index)
{
	static char	*final;
	int			len;

	if (!(final = ft_strnew(0)))
		return (NULL);
	if (!(final = read_all_file(fd, final)))
		return (NULL);
	len = (ft_strlen(final) + 1) / 21;
	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri) * (len + 1))))
		return (NULL);
	if (len == 1)
	{
		tetri = for_one_tetri(tetri, final, index);
		return (tetri);
	}
	while (len--)
	{
		if (!(tetri = for_multi_tetri(tetri, final, index)))
			return (NULL);
		index++;
	}
	tetri[index].piece = NULL;
	return (tetri);
}
