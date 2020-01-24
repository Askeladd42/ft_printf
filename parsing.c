/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2020/01/24 14:20:17 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	toggling_flag(char c, t_print *printer, va_list ap, size_t i)
{
	if (c == '0' && !(printer->flags & MINUS))
		printer->flags |= (1);
	else if (c == '-')
		printer->flags |= (1 << 1);
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
			printer->size = va_arg(ap, unsigned int);
			printer->flags |= (1 << 2);
		}
	}
	i++;
	/* BONUS:
	else if (c == ' ')
	else if (c == '#')
	else if (c == ''')
	else if (c == '+')
	*/
}

void	flag_parser(t_print *printer, const char *fmt, va_list ap, size_t i)
{
	while (fmt[i] != '%' && fmt[i])
		ft_putchar(fmt[i++]);
	printf("flag = %i\n", printer->flags);
	printf("width = %zu\n", printer->size);
	printf("acc = %zu\n", printer->acc);
	while (!ft_strchr("cspdiuxX%", fmt[++i]))
	{
		toggling_flag(fmt[i], printer, ap, i);
		printf("flag = %i\n", printer->flags);
		printer->size = (printer->flags & L_ASTERISK ? printer->size : width(fmt, i));
		printf("width = %zu\n", printer->size);
		printer->acc = (printer->flags & R_ASTERISK ? printer->acc : accuracy(fmt, i));
		printf("acc = %zu\n", printer->acc);
	}
	converter(fmt[i++], printer);
	printf("conversion = %i\n",printer->cnv);
	total_print(printer, ap);
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
		printer->buff = va_arg(ap, char *);
		if (printer->buff == NULL)
			ft_putstr("(null)");
		while (printer->acc > 0 && *str)
		{
			ft_putchar(*str++);
			printer->acc--;
		}
	}
	else if (printer->cnv & INTEGER)
	{
		str = conv(va_arg(ap, int), printer);
		printf("%s\n", str);
		ft_putstr(str);
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
