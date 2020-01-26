/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:46:24 by plam              #+#    #+#             */
/*   Updated: 2020/01/26 14:51:42 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	buffer_register(t_print *printer, char *str)
{
	size_t	i;
	size_t	z;
	size_t	sp;

	i = 0;
	z = set_zeros(printer);
	sp = set_spaces(printer);
	if (printer->flags & MINUS)
	{
		while (z-- > 0)
			printer->buff[i++] = '0';
		while (*str && i < 64)
			printer->buff[i++] = *str++;
		while (sp-- > 0)
			printer->buff[i++] = ' ';
	}
	else
	{
		while (sp-- > 0)
			printer->buff[i++] = ' ';
		while (*str && i < 64)
			printer->buff[i++] = *str++;
		while (z-- > 0)
			printer->buff[i++] = '0';
	}
}
