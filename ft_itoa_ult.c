/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:25:43 by plam              #+#    #+#             */
/*   Updated: 2020/01/26 10:17:38 by plam             ###   ########.fr       */
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

char			*ft_itoa_ult(int n, char *charset, t_print *dest) // probleme d'utilisation de structure
{
	char			*buff;
	unsigned int	nbr;
	unsigned int	index;
	unsigned int	size;

	nbr = (n < 0) ? -n : n;
	size = ft_strlen(charset);
	dest->index = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	index = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	printf("index = %u\n", index);
	buff[index] = '\0';
	printf("index in printer = %zu\n", dest->index);
	while (index-- > 0)
	{
		buff[index] = charset[nbr % size];
		nbr /= size;
	}
	if (n < 0)
		buff[0] = '-';
	ft_putstr(buff);
	return (buff);
}

char			*ft_itoa_alt(int n, char *charset)
{
	char			*buff;
	unsigned int	nbr;
	unsigned int	index;
	unsigned int	size;

	nbr = (n < 0) ? -n : n;
	size = ft_strlen(charset);
	index = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	buff[index] = '\0';
	while (index-- > 0)
	{
		buff[index] = charset[nbr % size];
		nbr /= size;
	}
	if (n < 0)
		buff[0] = '-';
	return (buff);
}

char			*ft_utoa_ult(unsigned int n, char *charset, t_print *dest)
{
	char			*buff;
	unsigned int	nbr;
	unsigned int	index;
	unsigned int	size;

	nbr = n;
	size = ft_strlen(charset);
	dest->index = nb_len(nbr, charset);
	index = nb_len(nbr, charset);
	buff[index] = '\0';
	while (index-- > 0)
	{
		buff[index] = charset[nbr % size];
		nbr /= size;
	}
	return (buff);
}
