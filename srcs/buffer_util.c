/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:46:24 by plam              #+#    #+#             */
/*   Updated: 2020/02/23 13:48:23 by plam             ###   ########.fr       */
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
	sp -= (sp > 0 && printer->buff[0] == '-'
			&& (int)printer->index == printer->acc ? 1 : 0);
	while (printer->buff[i])
		i++;
	if (printer->flags & ZEROS && !(printer->flags & MINUS))
		condition_zero(printer, z, sp);
	else
	{
		while (sp-- > 0)
		{
			if (printer->flags & MINUS)
				printer->buff[i++] = ' ';
			else
				ft_putchar(' ');
		}
	}
	printer->buff[i] = '\0';
	last_int_treatment(printer);
}

size_t	len_add(t_print *printer)
{
	if (printer->cnv & STRING)
		return (len_add_string(printer));
	if (printer->acc >= printer->size && printer->acc >= (int)printer->index)
		return (printer->acc);
	else if (printer->size >= printer->acc &&
			printer->size >= (int)printer->index)
		return (printer->size);
	else
		return (printer->index);
}

void	string_treatment(t_print *printer, char *str, size_t sp)
{
	str = ((str == NULL) ? "(null)" : str);
	printer->index = ft_strlen(str);
	printer->acc = (printer->acc > (int)printer->index ?
					ft_strlen(str) : printer->acc);
	printer->size = (printer->size < 0 ? (int)printer->index : printer->size);
	sp = set_spaces(printer);
	string_printer(str, sp, printer);
}

void	string_printer(char *str, size_t sp, t_print *printer)
{
	if (printer->flags & MINUS)
	{
		if ((printer->acc < (int)printer->index) && printer->acc >= 0
			&& (printer->flags & POINT))
			write(1, str, printer->acc);
		else
			ft_putstr(str);
		while ((int)sp <= printer->size && sp-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while ((int)sp <= printer->size && sp-- > 0)
		{
			if (printer->flags & ZEROS)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		if ((printer->acc < (int)printer->index) && printer->acc >= 0
			&& (printer->flags & POINT))
			write(1, str, printer->acc);
		else
			ft_putstr(str);
	}
}
