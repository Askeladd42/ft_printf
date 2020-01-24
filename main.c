/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2020/01/24 14:18:37 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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

int	main(void)
{
	//printf("bruh %-10.7d\n", 1001);
	printf("* OG Printf = Bonjour les gens,\nbonjour %-*.*i,\ncomment allez-vous ?\n", 8, 4, 42);
	ft_printf("* ft_printf = Bonjour les gens,\nbonjour %-*.*i,\ncomment allez-vous ?\n", 8, 4, 42);
	//printf("my function = %s\n", ft_itoa_alt(-78954, "0123456789"));
	return (0);
}
