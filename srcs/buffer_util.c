/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:46:24 by plam              #+#    #+#             */
/*   Updated: 2020/02/08 12:18:08 by plam             ###   ########.fr       */
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
		if (printer->flags & MINUS || printer->flags & ZEROS)
			printer->buff[i++] = ' ';
		else
			ft_putchar(' ');
	}
	printer->buff[i] = '\0';
	ft_putstr(printer->buff);
}

size_t	len_add(t_print *printer)
{
	if (printer->acc >= (int)printer->size
		&& printer->acc >= (int)printer->index)
		return (printer->acc);
	else if ((int)printer->size >= printer->acc &&
			printer->size >= printer->index)
		return (printer->size);
	else
		return (printer->index);
}
