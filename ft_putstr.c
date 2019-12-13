/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:56 by plam              #+#    #+#             */
/*   Updated: 2019/12/13 16:03:51 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '%' && s[i])
	{
		if (s[i] == '\\')
		{
			i++;
			if (s[i] == 'n')
			{
				write(1, "\n", 1);
				i++;
			}
		}
		write(1, &s[i++], 1);
	}
}
