/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:32:02 by plam              #+#    #+#             */
/*   Updated: 2020/01/17 10:23:37 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	size;
	t_print	printer;

	size = 0;
	va_start(ap, format);
	while (*format)
	{
		printer.flags = 0;
		printer.cnv = 0;
		printer.index = 0;
		flag_parser(printer, format, ap);
		total_print(printer, ap);
		size += printer.index;
	}
	va_end(ap);
	return (size);
}
