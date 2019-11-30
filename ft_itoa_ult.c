/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 10:25:43 by plam              #+#    #+#             */
/*   Updated: 2019/11/30 14:48:17 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	nb_len(unsigned int n, char *charset)
{
	int	i;
	int	len;

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

char		*ft_itoa_ult(int n, char *charset)
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
		dest[len] = '0' + nbr % c_len; // a corriger 
		nbr /= c_len;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
