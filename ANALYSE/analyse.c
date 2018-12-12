/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:31:21 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/06 15:04:35 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_is_next_line_valid(int fd, char ****tab)
{
	char	*line;

	line = NULL;
	get_next_line(fd, &line);
	if (line && line[0])
	{
		ft_tabdel(**tab);
		return (-1);
	}
	return (0);
}

int		ft_fd_into_tab(int fd, char **tab)
{
	int		verti;
	int 	hori;
	int		ret;

	verti = 0;
	hori = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 27)))
		return (-1);
	//ft_bzero(*tab, 1);
	tab[26] = 0;
	while (tab[verti])
	{
		hori = 0;
		if (!(tab[verti] = (char *)malloc(sizeof(char) * 5)))
		{
			ft_tabdel(tab);
			return (-1);
		}
		//ft_bzero(**tab, 1);
		tab[verti][4] = 0;
		while (tab[verti][hori])
			ret = get_next_line(fd, tab[verti][hori++]);
		verti++;
		ft_is_next_line_valid(fd, tab);
		if (ret == 0)
			break ;
	}
	tab[verti] = 0;
	return (1);
}

int		main(int ac, char **av)
{
    int fd;
	int i;
	int j;
	char **tab;

	tab = NULL;
	(void)ac;
	i = 0;
	j = 0;
    fd = open(av[1], O_RDONLY);
	ft_fd_into_tab(fd, &tab);
	if (ac < 2 || ac >= 3)
		return (-1);
    if (tab)
	{
		//while (tab[i][j])
		while (tab)
		{
			ft_print_words_tables(&tab[j++]);
			ft_putchar('\n');
			i++;
		}
	}
    close(fd);
    return (0);
}
