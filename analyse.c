/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:15:40 by cfauvell          #+#    #+#             */
/*   Updated: 2018/12/12 17:25:27 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//Fonction qui recupère tout le fichier d'un coup
char	*read_all_file(int fd, char *buff, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;

	*ret = read(fd, tmp, BUFF_SIZE);
	tmp[*ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (NULL);
	if (buff[0] == '\n' || ft_strlen(buff) > 545)
		return (NULL);
	ft_strdel(&tmp2);
	return(buff);
}

//Fonction qui permet de repartir le fichier en t_tetri *
t_tetri	*sort_tetri(int fd, t_tetri *test, int i)
{
	static char *final;
	char *tmp;
	int ret;

	ret = 0;
	if (!final && !(final = ft_strnew(0)))
			return (0);
	if(!(final = read_all_file(fd, final, &ret)))
		return (0);
	if ((tmp = ft_strstr(final, "\n\n")) != NULL)
		*tmp = '\0';
	if(!(test[i].piece = ft_strsplit(final, '\n')))
		return (NULL);
	if (!(ft_memmove(final, tmp + 2, ft_strlen(tmp + 1) + 1)))
		return (NULL);
	return (test);
}

/*Permet de tester le tetriminos(sans la reconnaissance des pieces pour 
le moment)*/
int		check_tetri(char **tab)
{
	int x;
	int y;
	int k;

	y = 0;
	k = 0;
	while (tab[y])
	{
		x = 0;
		while(tab[y][x])
		{
			if (tab[y][x] != '.' && tab[y][x] != '#')
				return (0);
			if (tab[y][x] == '#')
				k++;
			x++;
		}
		if (x != 4)
			return (0);
		y++;
	}
	if (y != 4 || k != 4)
		return (0);
	else
		return (1);
}

//Fonction censée mettre tout dans le pointeur sur structure
int		main(void)
{
	t_tetri	*test;
	int fd;
	int i;

	i = 0;
	fd = open ("test_4.fillit",  O_RDONLY);
	if (!(test = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	while (i < 4)
	{
		if(!(test = sort_tetri(fd, test, i)))
		{
			ft_putstr("NEED VALID FILE 😉\n");
			return (0);
		}
		if (!(check_tetri(test[0].piece)))
		{
			ft_putstr("NEED VALID TETRIMINOS 🙌\n");
			return (0);
		}
		ft_print_words_tables(test[i].piece);
		ft_putstr("\n");
		i++;
		test[i].index = i;
		ft_putnbr(test[0].index);
	}
	ft_putstr("\n");
	close (fd);
}

/*Reste a faire:
- Verification des formes
- Mettre les tab dans le tableau de structure
- Donner un index au tetriminos
- Definir leur longeur/largeur
- Il faut que quand un tetriminos n'est pas bon tout le process s'arrete*/
