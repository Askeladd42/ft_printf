/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:32:02 by plam              #+#    #+#             */
/*   Updated: 2020/02/02 11:23:41 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...) //faire en sorte de sauvegarder la position du i
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
		i = flag_parser(&printer, format, ap, i);
		size += (len_add(&printer) > 0 ? len_add(&printer) - 1 : 0);
		//printf("size = %zu\n", size);
	}
	va_end(ap);
	printf("printf return = %zu\n", size + i);
	return (size + i);
}
