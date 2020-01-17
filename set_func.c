/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:33:24 by plam              #+#    #+#             */
/*   Updated: 2020/01/17 10:56:49 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	accuracy(const char *fmt, size_t i)
{
	size_t	acc;

	acc = 0;
	if (fmt[i] == '.')
	{
		if (fmt[i] >= '1' && fmt[i] <= '9')
			acc = (unsigned int)ft_atoi_simple(&fmt[i]);
	}
	i++;
	return (acc);
}

size_t	width(const char *fmt, size_t i)
{
	size_t	len;

	len = 0;
	if (fmt[i] >= '1' && fmt[i] <= '9')
		len = (unsigned int)ft_atoi_simple(&fmt[i]);
	i++;
	return (len);
}

void	set_spaces(t_print printer)
{
	size_t	sp;

	sp = (printer.acc > printer.size ?
		printer.acc : printer.size - printer.acc);
	while (sp > 0)
		ft_putchar(' ');
}

void	set_zeros(t_print printer)
{
	size_t	zeros;

	zeros = (printer.acc > ft_strlen(printer.buff) ?
			printer.acc - ft_strlen(printer.buff) : printer.acc);
	while (zeros > 0)
		ft_putchar('0');
}
