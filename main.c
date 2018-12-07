/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:53:12 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/04 12:42:20 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_is_fd_valid(int fd)
{
	int ret;
	char *temp;
	static char **tab;
	int i;

	i = 0;
	temp = ft_strnew(5);
	while ((ret = read(fd, temp, sizeof(temp)) != 0))
	{
		tab[i] = temp;
		free(temp);
		i++;
	}
	/*while (temp[i] && line < 4)
	{
		while (temp[i] != '\n')
			i++;
		line++;
		if (temp[i + 1] != '\n')
			return (-1);
	}*/
	return (0);
}

int		main(int ac, char **av)
{
    int fd;
    //char *line;
    int ret;

    //line = NULL;
	(void)ac;
    fd = 0;
    fd = open(av[1], O_RDONLY);
	printf("%d\n", ft_is_fd_valid(fd));
	/*while ((ret = get_next_line(fd, &line)) > 0)
    {
        ft_putnbr(ret);
        ft_putendl(line);
        //ft_putchar('\n');
        free(line);
        line = NULL;
    }*/
    //ft_putendl(line);
    //ft_putnbr(ret);
    //free(line);
    close(fd);
    return (0);
}
