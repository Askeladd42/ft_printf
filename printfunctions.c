/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:23:47 by plam              #+#    #+#             */
/*   Updated: 2019/12/01 11:33:03 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	stringer(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
		write(1, &format[i++], 1);
	return (i);
}

void	hexa(char *offset, int hex)
{
	size_t	i;
	char *disp;

	i = 0;
	if (offset[i] == '%' && offset[i + 1] == 'p')
	{
		disp = ft_itoa_ult(hex, "0123456789abcdef");
		write(1, "0x", 2);
		write(1, disp, ft_strlen(disp));
		write(1, "\n", 1);
	}
}