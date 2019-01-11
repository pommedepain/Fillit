/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file.1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:52:34 by cfauvell          #+#    #+#             */
/*   Updated: 2019/01/10 22:55:00 by cfauvell         ###   ########.fr       */
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

int		sort_tetri(char *str, t_tetri *test, int i)
{
	char	*tmp;
	char	*tmp2;

	if ((tmp = ft_strstr(str, "\n\n")) != NULL)
		*tmp = '\0';
	tmp2 = ft_strdup(str);
	tmp2 = clear_string1(tmp2);
	if (sort_particular_case(tmp2, test, i) == 1)
	{
		ft_memmove(str, tmp + 2, ft_strlen(tmp + 2));
		free(tmp2);
		return (1);
	}
	tmp2 = clear_string2(tmp2);
	if (!(test[i].piece = tab_filling(tmp2)))
		return (-1);
	ft_memmove(str, tmp + 2, ft_strlen(tmp + 2));
	free(tmp2);
	return (1);
}

/*
** Convert the file to a structure table
** (if valid)
*/

t_tetri	*put_in_struct(t_tetri *test, int fd, int index)
{
	static char	*final;
	int			len;

	if (!(final = ft_strnew(0)))
		return (NULL);
	if (!(final = read_all_file(fd, final)))
		return (NULL);
	len = (ft_strlen(final) + 1) / 21;
	if (!(test = (t_tetri *)malloc(sizeof(t_tetri) * (len + 1))))
		return (NULL);
	while (len--)
	{
		if (!(sort_tetri(final, test, index)))
		{
			return (NULL);
		}
		if (!(check_tetri(test[index++].piece)))
		{
			free_all(test);
			return (NULL);
		}
		test[index - 1].index = index;
		test[index - 1].alpha = 64 + index;
	}
	test[index].piece = NULL;
	return (test);
}
