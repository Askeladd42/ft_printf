/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2019/12/07 16:59:02 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parsing_path(char *s, va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = stringer(&s[i]);
	if (str[i++] == 'l')
		if (str[i++] == 'l')
			if (str[i] == 'd' || str[i] == 'i')
				va_arg(ap, long long int);
			else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
				va_arg(ap, unsigned long long int);
		else if (str[i] == 'd' || str[i] == 'i')
			va_arg(ap, long int);
		else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
			va_arg(ap, unsigned long int);
	else if (str[i++] == 'h')
		if (str[i++] == 'h')
			if (str[i] == 'd' || str[i] == 'i')
				va_arg(ap, char);
			else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
				va_arg(ap, unsigned char);
		else if (str[i] == 'd' || str[i] == 'i')
			va_arg(ap, short int);
		else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
			va_arg(ap, unsigned short int);
}
