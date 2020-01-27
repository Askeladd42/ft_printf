/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:33:24 by plam              #+#    #+#             */
/*   Updated: 2020/01/27 10:59:24 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	accuracy(const char *fmt, size_t i, t_print *printer)
{
	size_t	acc;

	acc = printer->acc;
	if (fmt[i++] == '.')
	{
		if (fmt[i] >= '0' && fmt[i] <= '9')
			acc = (unsigned int)ft_atoi_simple(&fmt[i]);
	}
	i++;
	return (acc);
}

size_t	width(const char *fmt, size_t i, t_print *printer)
{
	size_t	len;

	len = printer->size;
	if (fmt[i] >= '0' && fmt[i] <= '9')
		len = (unsigned int)ft_atoi_simple(&fmt[i]);
	i++;
	return (len);
}

size_t	set_spaces(t_print *printer)
{
	size_t	sp;

	sp = (printer->acc > printer->size ?
		printer->acc : printer->size - printer->acc);
	printf("sp = %zu\n", sp);
	return (sp);
}

size_t	set_zeros(t_print *printer)
{
	size_t	zeros;

	zeros = (printer->acc > printer->index ?
			printer->acc - printer->index : printer->acc);
	zeros = (printer->cnv & ADDRESS ? zeros - 2 : zeros);
	printf("zeros = %zu\n", zeros);
	return (zeros);
}
