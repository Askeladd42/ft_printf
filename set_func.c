/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:33:24 by plam              #+#    #+#             */
/*   Updated: 2020/02/03 10:58:55 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	accuracy(const char *fmt, size_t i, t_print *printer) // ne se lit pas lors d'un flag
{
	size_t	acc;

	acc = printer->acc;
	if (printer->flags & POINT)
	{
		if (fmt[i] >= '0' && fmt[i] <= '9')
		{
			acc = (unsigned int)ft_atoi_simple(&fmt[i]);
			while (fmt[i] >= '0' && fmt[i] <= '9')
				i++;
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
	if (fmt[i] >= '0' && fmt[i] <= '9')
	{
		len = (unsigned int)ft_atoi_simple(&fmt[i]);
		while (fmt[i] >= '0' && fmt[i] <= '9')
			i++;
	}
	else
		i++;
	return (len);
}

size_t	set_spaces(t_print *printer)
{
	size_t	sp;

	sp = len_add(printer) - (printer->index + set_zeros(printer));
	if (printer->index >= len_add(printer))
		sp = 0;
	//printf("sp = %zu\n", sp);
	return (sp);
}

size_t	set_zeros(t_print *printer)
{
	size_t	zeros;

	zeros = (printer->acc >= printer->index ?
			printer->acc - printer->index : 0);
	if (printer->index >= len_add(printer))
		zeros = 0;
	//printf("zeros = %zu\n", zeros);
	return (zeros);
}
