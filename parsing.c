/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2019/12/08 10:42:27 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parsing_path(char *s, va_list ap)
{
	size_t	i;

	i = stringer(s);
	if (s[i] == 'c')
		va_arg(ap, char);
	else if (s[i] == 's')
		va_arg(ap, char *);
	else if (s[i] == 'd' || s[i] == 'i')
		va_arg(ap, int);
	else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'p')
		va_arg(ap, unsigned int);
}

void	parsing_path_extra(char *s, va_list ap)
{
	size_t	i;

	i = stringer(s);
	if (s[i++] == 'l')
		if (s[i++] == 'l')
			if (s[i] == 'd' || s[i] == 'i')
				va_arg(ap, long long int);
			else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
				va_arg(ap, unsigned long long int);
		else if (s[i] == 'd' || s[i] == 'i')
			va_arg(ap, long int);
		else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
			va_arg(ap, unsigned long int);
	else if (s[i++] == 'h')
		if (s[i++] == 'h')
			if (s[i] == 'd' || s[i] == 'i')
				va_arg(ap, char);
			else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
				va_arg(ap, unsigned char);
		else if (s[i] == 'd' || s[i] == 'i')
			va_arg(ap, short int);
		else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
			va_arg(ap, unsigned short int);
}
