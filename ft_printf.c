/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:32:02 by plam              #+#    #+#             */
/*   Updated: 2019/12/08 12:44:46 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	size;
	size_t	i;


	i = 0;
	size = 0;
	va_start(ap, format);
	while (format[i])
	{
		size += stringer(&format[i]);
		parsing_path_extra(format, ap);
		parsing_path(format, ap);
	}
	va_end(ap);
	return (size);
}
