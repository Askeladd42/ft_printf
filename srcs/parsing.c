/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2020/02/23 13:43:22 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	toggling_flag(char c, t_print *printer, va_list ap)
{
	if (c == '0' && !(printer->flags & MINUS) && !(printer->flags & POINT))
		printer->flags |= (1);
	else if (c == '-')
		toggling_minus(printer);
	else if (c == '.')
		printer->flags |= (1 << 3);
	else if (c == '*')
	{
		if (printer->flags & POINT)
		{
			printer->flags |= (1 << 4);
			printer->acc = va_arg(ap, unsigned int);
		}
		else if (!(printer->flags & POINT))
		{
			printer->size = va_arg(ap, int);
			if (printer->size < 0)
			{
				toggling_minus(printer);
				printer->size = -printer->size;
			}
			printer->flags |= (1 << 2);
		}
	}
}

size_t	flag_parser(t_print *printer, const char *fmt, va_list ap, size_t i)
{
	while (fmt[i] && fmt[i] != '%')
	{
		ft_putchar(fmt[i++]);
		printer->cnt++;
	}
	i += (fmt[i] == '%' ? 1 : 0);
	if (fmt[i - 1] == '%')
	{
		while (fmt[i] && !ft_strchr("cspdiuxX%", fmt[i]))
		{
			toggling_flag(fmt[i], printer, ap);
			printer->size = (printer->flags & L_ASTERISK ?
					printer->size : width(fmt, i, printer));
			printer->acc = (printer->flags & R_ASTERISK ?
					printer->acc : accuracy(fmt, i, printer));
			i += (fmt[i] >= '0' && fmt[i] <= '9') ? passing_nb(fmt, i) : 1;
		}
		converter(fmt[i++], printer);
		print_converter(printer, ap);
	}
	return (i);
}

void	converter(char c, t_print *printer)
{
	if (c == 'c')
		printer->cnv |= (1);
	else if (c == 's')
		printer->cnv |= (1 << 1);
	else if (c == 'p')
		printer->cnv |= (1 << 2);
	else if (c == 'd' || c == 'i')
		printer->cnv |= (1 << 3);
	else if (c == 'u')
		printer->cnv |= (1 << 4);
	else if (c == 'x')
		printer->cnv |= (1 << 5);
	else if (c == 'X')
		printer->cnv |= (1 << 6);
	else if (c == '%')
		printer->cnv |= (1 << 7);
}

void	print_converter(t_print *printer, va_list ap)
{
	char	*str;
	size_t	sp;

	sp = 0;
	if (printer->cnv & CHARACTER)
		char_treatment(printer, va_arg(ap, int), sp);
	else if (printer->cnv & PERCENT)
		char_treatment(printer, '%', sp);
	else if (printer->cnv & STRING)
	{
		str = va_arg(ap, char *);
		string_treatment(printer, str, sp);
	}
	else
		print_converter2(printer, ap);
}

void	print_converter2(t_print *printer, va_list ap)
{
	char	*str;

	str = NULL;
	if (printer->cnv & INTEGER)
	{
		str = conv(va_arg(ap, int), printer);
		buffer_register(printer);
	}
	else if (printer->cnv & U_INTEGER || printer->cnv & L_HEX
			|| printer->cnv & H_HEX)
	{
		str = uns_conv(va_arg(ap, unsigned int), printer);
		buffer_register(printer);
	}
	else if (printer->cnv & ADDRESS)
	{
		str = ad_conv(va_arg(ap, unsigned long long), printer);
		buffer_register(printer);
	}
}
