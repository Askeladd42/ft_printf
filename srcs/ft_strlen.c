/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:43:09 by plam              #+#    #+#             */
/*   Updated: 2020/02/22 15:46:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	check_neg_zero(t_print *printer, size_t z)
{
	if (printer->buff[0] == '-')
	{
		if ((!(printer->flags & POINT) && printer->size > (int)printer->index) ||
		(printer->acc > (int)printer->index && (ft_atoi_simple(printer->buff) != 0)))
			printer->buff[0] = '0';
		z--;
	}
}

void	condition_zero(t_print *printer, size_t z, size_t sp)
{
	check_neg_zero(printer, z);
	if (!(printer->flags & POINT))
	{
		if (printer->buff[0] == '0' && ft_atoi_simple(printer->buff) != 0)
		{
			ft_putchar('-');
			sp -= (sp > 0 ? 1 : 0);
		}
		while (sp-- > 0)
			ft_putchar('0');
	}
	else
	{
		while (sp-- > 0)
			ft_putchar(' ');
		if ((!(printer->flags & POINT) && printer->size > (int)printer->index)
		|| (printer->acc > (int)printer->index
			&& ft_strlen(printer->buff) == printer->index))
		{
			ft_putchar('-');
			sp--;
		}
	}
}
