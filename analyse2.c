/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:07:56 by psentilh          #+#    #+#             */
/*   Updated: 2018/12/04 17:20:30 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     ft_fd_into_tab(int fd, char ****tab)
{
    char    *line;
    int     i;
    int     j;
    int     ret;

    i = 0;
    j = 0;
    line = NULL;
    // on malloc au nbr max de tetriminos + 1 pour le 0
    if (!(*tab = (char ***)malloc(sizeof(char **) * 27)))
        return (-1);
    // on met à 0 la dernière case
    (*tab)[26] = 0;
    // tant qu'il y a des tetriminos
    while ((*tab)[i])
    {
        j = 0;
        // on malloc 5 lignes par tetriminos (la dernière pour le 0)
        if (!((*tab)[i] = (char **)malloc(sizeof(char *) * 5)))
        {
            // si allocation échoue, on boucle pour free tout le tab
            ft_tabdel(**tab);
            return (-1);
        }
        // on met la dernière ligne à 0
        (*tab)[i][4] = 0;
        // tant qu'on a pas lu toutes les lignes du tetriminos actuel
        while ((*tab)[i][j])
        {
            // on stock ligne par ligne dans le tab
            ret = get_next_line(fd, &(*tab)[i][j++]);
        }
        // on passe à la ligne suivante
        i++;
        // on rappelle gnl pour vérifier si la ligne d'après est bien un \n (remplacé par gnl par un \0)
        get_next_line(fd, &line);
        // si line est créée et qu'elle contien qqchose, on free tout le tab
        if (line && line[0])
        {
            ft_tabdel(**tab);
            return (-1);
        }
        // s'il y n' a plus rien à lire, on sort de la boucle
        if (ret == 0)
            break ;
    }
    // met un \0 après le dernier tetriminos (comme on ne peut pas savoir à l'avance combien il y en a)
    (*tab)[i] = 0;
    return (1);
}

int     main(int ac, char **av)
{
	int fd;
    int i;
    int j;
    char ***tab;

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
        while (tab[i][j])
        {
            ft_print_words_tables(tab[j++]);
            ft_putchar('\n');
            i++;
        }
    }
	close(fd);
	return (0);
}
