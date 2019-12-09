/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2019/12/09 15:54:26 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

va_list		parsing_path(const char *s, va_list ap)
{
	size_t	i;

	i = stringer(s);
	if (s[i] == 'c')
		return (va_arg(ap, char));
	else if (s[i] == 's')
		return (va_arg(ap, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		return (va_arg(ap, int));
	else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
		return (va_arg(ap, unsigned int));
	else if (s[i] == 'p')
		return (va_arg(ap, unsigned long));
	else if (s[i] == 'e' || s[i] == 'f' || s[i] == 'g')
		return (va_arg(ap, double));
}

va_list		parsing_path_extra(const char *s, va_list ap)
{
	size_t	i;

	i = stringer(s);
	if (s[i++] == 'l')
		if (s[i++] == 'l')
			if (s[i] == 'd' || s[i] == 'i')
				return (va_arg(ap, long long int));
			else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
				return (va_arg(ap, unsigned long long int));
		else if (s[i] == 'd' || s[i] == 'i')
			return (va_arg(ap, long int));
		else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
			return (va_arg(ap, unsigned long int));
	else if (s[i++] == 'h')
		if (s[i++] == 'h')
			if (s[i] == 'd' || s[i] == 'i')
				return (va_arg(ap, char));
			else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
				return (va_arg(ap, unsigned char));
		else if (s[i] == 'd' || s[i] == 'i')
			return (va_arg(ap, short));
		else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
			return (va_arg(ap, unsigned short));
}

void	parse_print(const char *s, va_list ap, size_t i)
{
	while (s[i])
	{
		if (ap != parsing_path_extra(s, ap))
		{
			if (ap == va_arg(ap, char *))
				ft_putstr(conv(&s[i], ap));
			else if (ap == va_arg(ap, char))
				ft_putchar(ap);
			else if (ap == va_arg(ap, int))
				ft_putstr(conv(&s[i], ap));
			else if (ap == va_arg(ap, unsigned int) || ap == va_arg(ap, unsigned long))
				ft_putstr(uns_conv(&s[i], ap));
			//else if (ap == va_arg(ap, double))
		}
	}
}