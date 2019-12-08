/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2019/12/08 12:04:26 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parsing_path(const char *s, va_list *ap)
{
	size_t	i;

	i = stringer(s);
	if (s[i] == 'c')
		va_arg(ap, char);
	else if (s[i] == 's')
		va_arg(ap, char *);
	else if (s[i] == 'd' || s[i] == 'i')
		va_arg(ap, int);
	else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'p') //p est en unsigned long !
		va_arg(ap, unsigned int);
	else if (s[i] == 'e' || s[i] == 'f' || s[i] == 'g')
		va_arg(ap, double);
}

void	parsing_path_extra(const char *s, va_list *ap)
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
			va_arg(ap, short);
		else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
			va_arg(ap, unsigned short);
}
