/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2020/01/14 15:55:48 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* void		parsing_path(const char *s1, const char **v)
{
	size_t	i;
	size_t	len;
	size_t	acc;
	size_t	set_sp;
	size_t	set_len;
	t_print	dest;

	i = 0;
	set_len = 0;
	while (s1[i])
	{
		while (s1[i] != '%' && s1[i])
			ft_putchar(s1[i++]);
		i++;
		if (s1[i++] == '-')
		{
			len = width(s1, i++, v);
			acc = accuracy(s1, i++, v);
			i++;
			set_sp = (len - acc > 0 ? len - acc : 0);
		}
		if (s1[i] == 'c' || s1[i] == '%')
			ft_putchar(conv(&s1[i - 1], ft_atoi_simple(v[2]), dest)[0]);
		else if (s1[i] == 's')
		{
			set_len = ft_strlen(v[2]);
			while (set_len-- > 0)
				ft_putchar(*v[2]++);
		}
		else if (s1[i] == 'd' || s1[i] == 'i')
		{
			set_len = set_sp - ft_strlen(conv(&s1[i - 1], ft_atoi_simple(v[2]), dest));
			while (set_len-- > 0)
				ft_putchar('0');
			ft_putstr(conv(&s1[i - 1], ft_atoi_simple(v[2]), dest));
		}
		else if (s1[i] == 'u' || s1[i] == 'x' || s1[i] == 'X')
		{
			set_len = ft_strlen(uns_conv(&s1[i - 1], ft_atoi_simple(v[2]), dest));
			ft_putstr(uns_conv(&s1[i - 1], (unsigned int)ft_atoi_simple(v[2]), dest));
		}
		else if (s1[i] == 'p')
		{
			ft_putstr("0x");
			set_len = ft_strlen(uns_conv(&s1[i - 1], ft_atoi_simple(v[2]), dest)) + 2;
			while (set_len-- > 0)
				ft_putchar('0');
			ft_putstr(uns_conv(&s1[i - 1], (unsigned int)ft_atoi_simple(v[2]), dest));
		}
		set_sp = (set_sp - set_len > 0 ? set_sp - set_len : 0);
		while (set_sp > 0)
		{
			set_sp--;
			ft_putchar(' ');
		}
		i++;
	}
}
*/

void	toggling_flag(char c, t_print printer,  va_list ap)
{
	if (c == '0')
		printer.flags |= (1);
	else if (c == '-')
		printer.flags |= (1 << 1);
	else if (c == '.')
		printer.flags |= (1 << 3);
	else if (c == '*')
	{
		if ((printer.flags & POINT) && (printer.size == 0))
		{
			printer.size = va_arg(ap, unsigned int);
			printer.flags |= (1 << 4);
		}
		else if (!(printer.flags & POINT) && (printer.acc == 0))
		{
			printer.acc = va_arg(ap, unsigned int);
			printer.flags |= (1 << 2);
		}
	}
	/* BONUS:
	else if (c == ' ')
	*/
}

void	flag_parser(t_print printer, const char *fmt, va_list ap)
{
	size_t	i;

	i = 0;
	while (fmt[i] && fmt[i] != '%')
		ft_putchar(fmt[i++]);
	while (!ft_strchr("cspdiuxX%", fmt[i]))
	{
		printer.size = width(fmt, i);
		printer.acc = accuracy(fmt, i);
		toggling_flag(fmt[i++], printer, ap);
	}
	converter(fmt[i], printer);
	print_converter(printer, ap);
}

void	converter(char c, t_print printer)
{
	if (c == 'c')
		printer.cnv |= (1);
	else if (c == 's')
		printer.cnv |= (1 << 1);
	else if (c == 'p')
		printer.cnv |= (1 << 2);
	else if (c == 'd' || c == 'i')
		printer.cnv |= (1 << 3);
	else if (c == 'u')
		printer.cnv |= (1 << 4);
	else if (c == 'x')
		printer.cnv |= (1 << 5);
	else if (c == 'X')
		printer.cnv |= (1 << 6);
}

void	print_converter(t_print printer, va_list ap)
{
	size_t	i;

	i = 0;
	/* à adapter aux nouvelles donneées :
	if (s1[i] == 'c' || s1[i] == '%')
			ft_putchar(conv(&s1[i - 1], ft_atoi_simple(v[2]), dest)[0]);
		else if (s1[i] == 's')
		{
			set_len = ft_strlen(v[2]);
			while (set_len-- > 0)
				ft_putchar(*v[2]++);
		}
		else if (s1[i] == 'd' || s1[i] == 'i')
		{
			set_len = set_sp - ft_strlen(conv(&s1[i - 1], ft_atoi_simple(v[2]), dest));
			while (set_len-- > 0)
				ft_putchar('0');
			ft_putstr(conv(&s1[i - 1], ft_atoi_simple(v[2]), dest));
		}
		else if (s1[i] == 'u' || s1[i] == 'x' || s1[i] == 'X')
		{
			set_len = ft_strlen(uns_conv(&s1[i - 1], ft_atoi_simple(v[2]), dest));
			ft_putstr(uns_conv(&s1[i - 1], (unsigned int)ft_atoi_simple(v[2]), dest));
		}
		else if (s1[i] == 'p')
		{
			ft_putstr("0x");
			set_len = ft_strlen(uns_conv(&s1[i - 1], ft_atoi_simple(v[2]), dest)) + 2;
			while (set_len-- > 0)
				ft_putchar('0');
			ft_putstr(uns_conv(&s1[i - 1], (unsigned int)ft_atoi_simple(v[2]), dest));
		}
		set_sp = (set_sp - set_len > 0 ? set_sp - set_len : 0);
		while (set_sp > 0)
		{
			set_sp--;
			ft_putchar(' ');
		}
		i++;
	*/
}
