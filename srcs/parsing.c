/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2020/02/09 13:57:10 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* adapter les fonctions pour les adresses et les srings pour qu'ils comptent 
	correctement le nombre de caractères imprimés + fixer le reste de segfault */

void	toggling_flag(char c, t_print *printer, va_list ap)
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
}

size_t	flag_parser(t_print *printer, const char *fmt, va_list ap, size_t i)
{
	while (fmt[i] && fmt[i] != '%')
		ft_putchar(fmt[i++]);
	i += (fmt[i] ? 1 : 0);
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
	total_print(printer, ap);
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
	{
		str = NULL;
		ft_putchar(va_arg(ap, int));
	}
	else if (printer->cnv & PERCENT)
		ft_putchar('%');
	else if (printer->cnv & STRING)
	{
		str = va_arg(ap, char *);
		str = (str == NULL ? "(null)" : str);
		sp = len_add(printer) - ft_strlen(str);
		if ((int)ft_strlen(str) > printer->acc)
			write(1, str, printer->acc);
		else
			ft_putstr(str);
	}
	else if (printer->cnv & INTEGER)
	{
		str = conv(va_arg(ap, int), printer);
		buffer_register(printer);
	}
	else if (printer->cnv & U_INTEGER || printer->cnv & L_HEX
			|| printer->cnv & H_HEX || printer->cnv & ADDRESS)
	{
		str = uns_conv(va_arg(ap, unsigned int), printer);
		buffer_register(printer);
	}
}

void	total_print(t_print *printer, va_list ap)
{
	if ((printer->flags & ZEROS) && !(printer->flags & MINUS))
	{
		if (printer->cnv & ADDRESS)
		{
			ft_putstr("0x10");
			printer->size -= (printer->size > 7 ? 4 : 0);
		}
		print_converter(printer, ap);
	}
	else if (printer->flags & MINUS)
	{
		if (printer->cnv & ADDRESS)
		{
			ft_putstr("0x10");
			printer->size -= (printer->size > 7 ? 4 : 0);
		}
		print_converter(printer, ap);
	}
	else
		print_converter(printer, ap);
}