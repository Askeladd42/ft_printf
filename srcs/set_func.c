/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:33:24 by plam              #+#    #+#             */
/*   Updated: 2020/02/19 18:04:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

size_t	passing_nb(const char *fmt, size_t i)
{
	size_t	add;

	add = 0;
	while (fmt[i + add] >= '0' && fmt[i + add] <= '9')
		add++;
	return (add);
}

int		accuracy(const char *fmt, size_t i, t_print *printer)
{
	int		acc;

	acc = printer->acc;
	if (printer->flags & POINT)
	{
		if (*(fmt + i) >= '0' && *(fmt + i) <= '9')
		{
			acc = ft_atoi_simple((fmt + i));
			printer->flags |= (1 << 4);
		}
		else
			i++;
	}
	return (acc);
}

size_t	width(const char *fmt, size_t i, t_print *printer)
{
	size_t	len;

	len = printer->size;
	if (fmt[i] >= '0' && fmt[i] <= '9' && !(printer->flags & POINT))
	{
		len = (unsigned int)ft_atoi_simple(&fmt[i]);
		while (fmt[i] >= '0' && fmt[i] <= '9')
			i++;
		printer->flags |= (1 << 2);
	}
	else
		i++;
	return (len);
}

size_t	set_spaces(t_print *printer)
{
	size_t	sp;

	sp = 0;
	if (printer->cnv & STRING)
	{
		if (printer->flags & POINT)
		{
			printer->acc = (printer->acc < 0 ? printer->index :
							printer->acc);
			sp = len_add(printer) - (printer->acc <= (int)printer->index ?
					printer->acc : printer->index);
		}
		else
			sp = len_add(printer) - printer->index;
	}
	else
		sp = len_add(printer) - (printer->index + set_zeros(printer));
	if (!(printer->cnv & STRING) && printer->index >= len_add(printer))
		sp = 0;
	return (sp);
}

size_t	set_zeros(t_print *printer)
{
	size_t	zeros;

	zeros = (printer->acc >= (int)printer->index ?
			printer->acc - printer->index : 0);
	if (printer->index >= len_add(printer))
		zeros = 0;
	return (zeros);
}
