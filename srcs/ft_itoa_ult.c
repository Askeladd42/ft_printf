/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:25:43 by plam              #+#    #+#             */
/*   Updated: 2020/02/15 11:51:47 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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

static size_t	nb_len2(long long n, char *charset)
{
	size_t		i;
	long long	len;

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

char			*ft_itoa_ult(int n, char *charset, t_print *dest)
{
	unsigned int	nbr;
	unsigned int	index;
	unsigned int	size;
	unsigned int	i;
	unsigned int	z;

	nbr = (n < 0) ? -n : n;
	size = ft_strlen(charset);
	dest->index = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	dest->acc = (n < 0 && (int)dest->index < dest->acc)
					? dest->acc + 1 : dest->index;
	index = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	z = set_zeros(dest);
	i = 0;
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
	unsigned int	i;
	unsigned int	z;

	nbr = n;
	size = ft_strlen(charset);
	dest->index = nb_len(nbr, charset);
	index = nb_len(nbr, charset);
	z = set_zeros(dest);
	i = 0;
	while (z-- > 0)
		dest->buff[i++] = '0';
	dest->buff[i + index] = '\0';
	while (index-- > 0)
	{
		dest->buff[i + index] = charset[nbr % size];
		nbr /= size;
	}
	return (dest->buff);
}

char			*ft_lltoa_ult(long long ad, char *charset, t_print *dest)
{
	long long		nbr;
	unsigned int	index;
	unsigned int	size;
	unsigned int	i;
	unsigned int	z;

	nbr = ad;
	size = ft_strlen(charset);
	dest->index = nb_len2(nbr, charset) + (dest->cnv & ADDRESS ? 2 : 0);
	index = nb_len2(nbr, charset);
	z = set_zeros(dest);
	i = 0;
	while (z-- > 0)
		dest->buff[i++] = '0';
	dest->buff[i + index] = '\0';
	while (index-- > 0)
	{
		dest->buff[i + index] = charset[nbr % size];
		nbr /= size;
	}
	return (dest->buff);
}
