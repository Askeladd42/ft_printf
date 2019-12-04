/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:25:43 by plam              #+#    #+#             */
/*   Updated: 2019/12/04 14:10:08 by plam             ###   ########.fr       */
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
	char			*dest;

	nbr = (n < 0) ? -n : n;
	c_len = ft_strlen(charset);
	len = (n < 0) ? nb_len(nbr, charset) + 1 : nb_len(nbr, charset);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	while (len-- > 0)
	{
		dest[len] = charset[nbr % c_len];
		nbr /= c_len;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}

char			*ft_utoa_ult(unsigned int n, char *charset)
{
	size_t			len;
	size_t			c_len;
	unsigned int	nbr;
	char			*dest;

	nbr = n;
	c_len = ft_strlen(charset);
	len = nb_len(nbr, charset);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	while (len-- > 0)
	{
		dest[len] = charset[nbr % c_len];
		nbr /= c_len;
	}
	return (dest);
}
