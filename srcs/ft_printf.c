/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:32:02 by plam              #+#    #+#             */
/*   Updated: 2020/02/14 13:33:14 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	size;
	size_t	i;
	t_print	printer;

	size = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		printer.index = 0;
		printer.flags = 0;
		printer.cnv = 0;
		printer.acc = 0;
		printer.size = 0;
		printer.cnt = 0;
		i = flag_parser(&printer, format, ap, i);
		size += printer.cnt + (len_add(&printer) > 0 ?
								len_add(&printer) - 1 : 0);
		ft_bzero(printer.buff, BUFFER_SIZE);
	}
	va_end(ap);
	return (size);
}
