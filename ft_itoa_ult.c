/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:25:43 by plam              #+#    #+#             */
/*   Updated: 2020/01/31 15:07:57 by plam             ###   ########.fr       */
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

char			*ft_itoa_ult(int n, char *charset, t_print *dest) // bug sur le compte des espaces
{
	unsigned int	nbr;
	unsigned int	index;
	unsigned int	size;
	unsigned int	i;
	unsigned int	z;
	unsigned int	len;

	nbr = (n < 0) ? -n : n;
	size = ft_strlen(charset);
	dest->index = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	dest->acc = (n < 0) ? dest->index + 1 : dest->index;
	index = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	z = (n < 0) ? set_zeros(dest) + 1 : set_zeros(dest);
	len = len_add(dest) - set_spaces(dest);
	i = 0;
	printf("z = %u, index = %u\n", z, index);
	while (z-- > 0)
		dest->buff[i++] = '0';
	while (index-- > 0)
	{
		dest->buff[i + index] = charset[nbr % size];
		nbr /= size;
	}
	if (n < 0)
		dest->buff[0] = '-';
	return (dest->buff);
}

char			*ft_utoa_ult(unsigned int n, char *charset, t_print *dest)
{
	unsigned int	nbr;
	unsigned int	index;
	unsigned int	size;
	unsigned int	len;

	nbr = n;
	size = ft_strlen(charset);
	dest->index = nb_len(nbr, charset);
	index = nb_len(nbr, charset);
	len = len_add(dest) - set_spaces(dest);
	dest->buff[len] = '\0';
	while (index-- > 0)
	{
		dest->buff[len--] = charset[nbr % size];
		nbr /= size;
	}
	while (len > 0)
		dest->buff[len--] = '0';
	return (dest->buff);
}