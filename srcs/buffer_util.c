/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:46:24 by plam              #+#    #+#             */
/*   Updated: 2020/02/17 13:24:03 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = 0;
}

void	buffer_register(t_print *printer)
{
	size_t	i;
	size_t	sp;
	size_t	z;

	i = 0;
	z = set_zeros(printer);
	sp = set_spaces(printer);
	while (printer->buff[i])
		i++;
	while (sp-- > 0)
	{
		if (printer->flags & MINUS)
			printer->buff[i++] = ' ';
		else
			ft_putchar(' ');
	}
	printer->buff[i] = '\0';
	if (printer->cnv & ADDRESS)
		ft_putstr("0x");
	ft_putstr(printer->buff);
}

size_t	len_add(t_print *printer)
{
	if (printer->acc >= printer->size && printer->acc >= (int)printer->index)
		return (printer->acc);
	else if (printer->size >= printer->acc &&
			printer->size >= (int)printer->index)
		return (printer->size);
	else if (printer->cnv & STRING && !(printer->flags & L_ASTERISK))
		return ((int)printer->index < printer->acc ?
				printer->index : printer->acc);
	else
		return (printer->index);
}

void	string_printer(char *str, size_t sp, t_print *printer)
{
	if (printer->flags & MINUS)
	{
		if ((printer->acc <= (int)printer->index) && printer->acc > 0)
			write(1, str, printer->acc);
		else
			ft_putstr(str);
		while ((int)sp < printer->size && sp-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while ((int)sp < printer->size && sp-- > 0)
			ft_putchar(' ');
		if (printer->acc <= (int)printer->index)
			write(1, str, printer->acc);
		else
			ft_putstr(str);
	}
}
