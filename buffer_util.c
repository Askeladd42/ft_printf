/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:46:24 by plam              #+#    #+#             */
/*   Updated: 2020/01/31 12:19:46 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	buffer_register(t_print *printer, char *str)
{
	size_t	i;
	size_t	sp;
	size_t	z;

	i = len_add(printer);
	z = set_zeros(printer);
	sp = set_spaces(printer);
	printf("z = %zu, sp = %zu & str = %s\n", z, sp, str);
	printer->buff[i] = '\0';
	if (printer->flags & MINUS || printer->flags & ZEROS)
	{
		while (i < 64)
			printer->buff[i++] = *str;
		while (sp-- > 0)
			printer->buff[i++] = ' ';
	}
	else
	{
		while (sp-- > 0)
			printer->buff[i++] = ' ';
		while (*str && i < 64)
			printer->buff[i++] = *str++;
	}
	printer->buff[i] = '\0';
	//printf("str after conversion = %s\n", str);
}

size_t	len_add(t_print *printer)
{
	if (printer->acc >= printer->size && printer->acc >= printer->index)
		return (printer->acc);
	else if (printer->size >= printer->acc && printer->size >= printer->index)
		return (printer->size);
	else
		return (printer->index);
}