/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:46:24 by plam              #+#    #+#             */
/*   Updated: 2020/02/07 13:30:45 by plam             ###   ########.fr       */
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

void	buffer_register(t_print *printer) // problème avec le nombre des espaces
{
	size_t	i;
	size_t	sp;
	size_t	z;

	i = 0;
	z = set_zeros(printer);
	sp = set_spaces(printer);
	//printf("buff = %s, z = %zu, sp = %zu\n", printer->buff, z, sp);
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

/*faire une fonction aui ajoute des espacements comme précédemment mais pour les string*/

size_t	len_add(t_print *printer)
{
	if (printer->acc >= printer->size && printer->acc >= printer->index)
		return (printer->acc);
	else if (printer->size >= printer->acc && printer->size >= printer->index)
		return (printer->size);
	else
		return (printer->index);
}