/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:56 by plam              #+#    #+#             */
/*   Updated: 2020/02/18 11:58:10 by plam             ###   ########.fr       */
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
						? printer->index : printer->acc);
	if (printer->flags & MINUS)
	{
		if ((printer->acc <= (int)printer->index) && printer->acc > 0)
			ft_putchar(c);
		while ((int)sp <= printer->size && sp-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while ((int)sp <= printer->size && sp-- > 0)
			ft_putchar(' ');
		if (printer->acc <= (int)printer->index)
			ft_putchar(c);
	}
}