/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2020/01/19 12:03:48 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	toggling_flag(char c, t_print *printer, va_list ap)
{
	if (c == '0')
		printer->flags |= (1);
	else if (c == '-')
		printer->flags |= (1 << 1);
	else if (c == '.')
		printer->flags |= (1 << 3);
	else if (c == '*')
	{
		if ((printer->flags & POINT) && (printer->size == 0))
		{
			printer->size = va_arg(ap, unsigned int);
			printer->flags |= (1 << 4);
		}
		else if (!(printer->flags & POINT) && (printer->acc == 0))
		{
			printer->acc = va_arg(ap, unsigned int);
			printer->flags |= (1 << 2);
		}
	}
	/* BONUS:
	else if (c == ' ')
	else if (c == '#')
	else if (c == ''')
	else if (c == '+')
	*/
}

void	flag_parser(t_print *printer, const char *fmt, va_list ap)
{
	size_t	i;

	i = 0;
	while (fmt[i] && fmt[i] != '%')
		ft_putchar(fmt[i++]);
	while (!ft_strchr("cspdiuxX%", fmt[i]))
	{
		toggling_flag(fmt[i++], printer, ap);
		printer->size = width(fmt, i);
		printer->acc = accuracy(fmt, i);
	}
	converter(fmt[i], printer);
	//print_converter(printer, ap);
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
	char *str;

	if (printer->cnv & CHARACTER)
	{
		str = NULL;
		ft_putchar(va_arg(ap, int));
	}
	else if (printer->cnv & PERCENT)
		ft_putchar('%');
	else if (printer->cnv & STRING)
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		while (printer->acc > 0 && *str)
		{
			ft_putchar(*str++);
			printer->acc--;
		}
	}
	else if (printer->cnv & INTEGER)
	{
		while (printer->acc > 0 && *str)
		{
			str = conv(va_arg(ap, int), printer);

			if (str)
			{
				ft_putchar(*str++);
				printer->acc--;
			}
		}
	}
	else if (printer->cnv & U_INTEGER || printer->cnv & L_HEX
				|| printer->cnv & H_HEX)
	{
		str = uns_conv(va_arg(ap, unsigned int), printer);
		while (printer->acc > 0 && *str)
		{
			ft_putchar(*str++);
			printer->acc--;
		}
	}
	else if (printer->cnv & ADDRESS)
	{
		str = uns_conv(va_arg(ap, unsigned int), printer);
		while (printer->acc > 0 && *str)
		{
			ft_putchar(*str++);
			printer->acc--;
		}
	}
}

void	total_print(t_print *printer, va_list ap)
{
	if ((printer->flags & ZEROS) && !(printer->flags & MINUS))
	{
		set_spaces(printer);
		if (printer->cnv & ADDRESS)
			ft_putstr("0x");
		set_zeros(printer);
		print_converter(printer, ap);
	}
	else if (printer->flags & MINUS)
	{
		if (printer->cnv & ADDRESS)
		{
			ft_putstr("0x");
			printer->size -= 2;
		}
		set_zeros(printer);
		print_converter(printer, ap);
		set_spaces(printer);
	}
	else
		print_converter(printer, ap);
}
