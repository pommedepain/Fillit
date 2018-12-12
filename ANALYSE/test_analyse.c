/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_analyse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:15:40 by cfauvell          #+#    #+#             */
/*   Updated: 2018/12/07 20:15:21 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//1Fonction qui permet de recuperer et verifier une ligne d'un tetriminos(BUFF_SIZE = 4)
/*char	*read_tetri(int fd, char *buff, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;

	*ret = read(fd, tmp, BUFF_SIZE);
	tmp[*ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (NULL);
	read(fd, tmp, 1);
	if (tmp[0] != '\n')
		return (NULL);
	ft_strdel(&tmp2);
	return (buff);
}

1Fonction qui permet de recuperer un tetriminos sur une ligne 
int		main(void)
{
	int fd;
	char *final;
	int ret;
	int i;

	ret = 0;
	i = 0;
	fd = open ("test1.fillit",  O_RDONLY);
	if (!(final = ft_strnew(BUFF_SIZE)))
		return (0);
	while (i++ < 4)
		if(!(final = read_tetri(fd, final, &ret)))
			return (0);
	ft_putstr(final);
	i = ft_strlen(final);
	ft_putnbr(i);
	close (fd);
	return (0);
}*/

//2Fonction qui recupère tout le fichier d'un coup(BUFF_SIZE = 546(taille maximum de notre fihier))
char	*read_all_file(int fd, char *buff, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;

	*ret = read(fd, tmp, BUFF_SIZE);
	tmp[*ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (NULL);
	ft_strdel(&tmp2);
	return(buff);
}

//2Fonction qui permet de repartir le fichier en **tab
char	**sort_tetri(fd)
{
	static char *final;
	char **piece;
	char *tmp;
	int ret;

	ret = 0;
	if (!final)
	{
		if (!(final = ft_strnew(BUFF_SIZE)))
			return (NULL);
	}
	if(!(final = read_all_file(fd, final, &ret)))
		return (0);
	if ((tmp = ft_strstr(final, "\n\n")) != NULL)
		*tmp = '\0';
	if(!(piece = ft_strsplit(final, '\n')))
		return (0);
	//chelou que ce soit tmp + 1 ou + 2 ca fait la meme chose
	if (!(ft_memmove(final, tmp + 1, ft_strlen(tmp + 1) + 1)))
		return (0);
	return (piece);
}



int		main(void)
{
	char **tab;
	char **tab1;
	int fd;
	
	fd = open ("test_27.fillit",  O_RDONLY);
	tab = sort_tetri(fd);
	ft_print_words_tables(tab);
	ft_putstr("\n");
	tab1 = sort_tetri(fd);
	ft_print_words_tables(tab1);
	close (fd);
}
