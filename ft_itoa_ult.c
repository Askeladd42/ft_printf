/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:25:43 by plam              #+#    #+#             */
/*   Updated: 2019/12/13 15:07:52 by plam             ###   ########.fr       */
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

char			*ft_itoa_ult(int n, char *charset)
{
	size_t			len;
	size_t			c_len;
	unsigned int	nbr;
	t_print			dest;

	nbr = (n < 0) ? -n : n;
	c_len = ft_strlen(charset);
	len = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	dest.buff[len] = '\0';
	while (len-- > 0)
	{
		dest.buff[len] = charset[nbr % c_len];
		nbr /= c_len;
	}
	if (n < 0)
		dest.buff[0] = '-';
	return (dest.buff);
}

char			*ft_utoa_ult(unsigned int n, char *charset)
{
	size_t			len;
	size_t			c_len;
	unsigned int	nbr;
	t_print			dest;

	nbr = n;
	c_len = ft_strlen(charset);
	len = nb_len(nbr, charset);
	dest.buff[len] = '\0';
	while (len-- > 0)
	{
		dest.buff[len] = charset[nbr % c_len];
		nbr /= c_len;
	}
	return (dest.buff);
}
