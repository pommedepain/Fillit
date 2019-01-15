/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:39:30 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/16 15:41:54 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	tmp_n;
	long	len;

	tmp_n = n;
	len = ft_digit_len(tmp_n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	if (tmp_n < 0)
		tmp_n = -tmp_n;
	while (len >= 0)
	{
		str[len] = (tmp_n % 10) + '0';
		len--;
		tmp_n /= 10;
	}
	if (ft_issign(n))
		str[0] = '-';
	return (str);
}
