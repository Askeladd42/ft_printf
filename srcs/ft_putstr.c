/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:56 by plam              #+#    #+#             */
/*   Updated: 2020/02/22 12:31:56 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '%' && s[i])
		write(1, &s[i++], 1);
}

void	char_treatment(t_print *printer, char c, size_t sp)
{
	printer->index = printer->acc > 0 ? printer->acc : 1;
	printer->size = (printer->size == 0 ? (int)printer->index :
											printer->size);
	sp = printer->size - (printer->acc > (int)printer->index
						? printer->index : printer->acc) - 1;
	if (printer->flags & MINUS)
	{
		ft_putchar(c);
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
		ft_putchar(c);
	}
}

size_t	len_add_string(t_print *printer)
{
	if (!(printer->flags & L_ASTERISK) || printer->size < 1)
	{
		if (!(printer->flags & R_ASTERISK) && !(printer->flags & POINT))
			return (printer->index);
		if (printer->acc != 0)
			return ((int)printer->index < printer->acc ?
				printer->index : printer->acc);
		else
			return (0);
	}
	else
	{
		if (!(printer->flags & POINT))
		{
			return (printer->size > (int)printer->index ?
				printer->size : printer->index);
		}
		if ((printer->flags & POINT) && printer->acc > 0 && printer->size == 0)
			return (printer->acc);
		if (((printer->flags & POINT) && (printer->acc < 1))
		|| (printer->size > printer->acc))
			return (printer->size);
		return ((int)printer->index < printer->acc ?
				printer->index : printer->acc);
	}
}
