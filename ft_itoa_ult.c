/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:25:43 by plam              #+#    #+#             */
/*   Updated: 2020/01/16 16:10:19 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	nb_len(unsigned int n, char *charset)
{
	size_t	i;
	size_t	len;

	i = 1;
	len = ft_strlen(charset);
	if (n == 0)
		return (1);
	while (n >= len)
	{
		i++;
		n /= len;
	}
	return (i);
}

char			*ft_itoa_ult(int n, char *charset, t_print dest)
{
	unsigned int	nbr;

	nbr = (n < 0) ? -n : n;
	dest.size = ft_strlen(charset);
	dest.index = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	dest.buff[dest.index] = '\0';
	while (dest.index-- > 0)
	{
		dest.buff[dest.index] = charset[nbr % dest.size];
		nbr /= dest.size;
	}
	if (n < 0)
		dest.buff[0] = '-';
	return (dest.buff);
}

char			*ft_utoa_ult(unsigned int n, char *charset, t_print dest)
{
	unsigned int	nbr;

	nbr = n;
	dest.size = ft_strlen(charset);
	dest.index = nb_len(nbr, charset);
	dest.buff[dest.index] = '\0';
	while (dest.index-- > 0)
	{
		dest.buff[dest.index] = charset[nbr % dest.size];
		nbr /= dest.size;
	}
	return (dest.buff);
}
