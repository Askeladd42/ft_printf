/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 08:42:44 by plam              #+#    #+#             */
/*   Updated: 2020/01/05 12:12:04 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*void		parsing_path(const char *s, va_list ap)
{
	size_t	i;

	i = stringer(s);
	if (s[i] == 'c')
		ap = va_arg(ap, char);
	else if (s[i] == 's')
		ap = va_arg(ap, char *);
	else if (s[i] == 'd' || s[i] == 'i')
		ap = va_arg(ap, int);
	else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
		ap = va_arg(ap, unsigned int);
	else if (s[i] == 'p')
		ap = va_arg(ap, unsigned long);
	else if (s[i] == 'e' || s[i] == 'f' || s[i] == 'g')
		ap = va_arg(ap, double);
}

void		parsing_path_extra(const char *s, va_list ap)
{
	size_t	i;

	i = stringer(s);
	if (s[i++] == 'l')
		if (s[i++] == 'l')
			if (s[i] == 'd' || s[i] == 'i')
				ap = va_arg(ap, long long int);
			else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
				ap = va_arg(ap, unsigned long long int);
		else if (s[i] == 'd' || s[i] == 'i')
			ap = va_arg(ap, long int);
		else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
			ap = va_arg(ap, unsigned long int);
	else if (s[i++] == 'h')
		if (s[i++] == 'h')
			if (s[i] == 'd' || s[i] == 'i')
				ap = va_arg(ap, char);
			else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
				ap = va_arg(ap, unsigned char);
		else if (s[i] == 'd' || s[i] == 'i')
			ap = va_arg(ap, short);
		else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
			ap = va_arg(ap, unsigned short);
}

void	parse_print(const char *s, va_list ap, size_t i)
{
	while (s[i])
	{
		if (ap != parsing_path_extra(s, ap))
		{
			if (ap == va_arg(ap, char *))
				ft_putstr(conv(&s[i], va_arg(ap, char *)));
			else if (ap == va_arg(ap, char))
				ft_putchar(va_arg(ap, char));
			else if (ap == va_arg(ap, int))
				ft_putstr(conv(&s[i], va_arg(ap, int)));
			else if (ap == va_arg(ap, unsigned int)
			|| ap == va_arg(ap, unsigned long))
				ft_putstr(va_arg(ap, unsigned int));
		}
	}
}
*/

void		parsing_path(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;
	size_t	acc;
	t_print	dest;

	i = 0;
	while (s1[i])
	{
		while (s1[i] != '%' && s1[i])
			ft_putchar(s1[i++]);
		i++;
		if (s1[i] == '-')
		{
			i++;
			acc = accuracy(s1, i);
			len = width(s1, i);
		}
		if (s1[i] == 'c' || s1[i] == '%')
			ft_putchar(conv(&s1[i - 1], ft_atoi_simple(s2), dest)[0]);
		else if (s1[i] == 's')
			ft_putstr(s2);
		else if (s1[i] == 'd' || s1[i] == 'i')
			ft_putstr(conv(&s1[i - 1], ft_atoi_simple(s2), dest));
		else if (s1[i] == 'u' || s1[i] == 'x' || s1[i] == 'X')
			ft_putstr(uns_conv(&s1[i - 1], (unsigned int)ft_atoi_simple(s2), dest));
		else if (s1[i] == 'p')
			ft_putstr(uns_conv(&s1[i - 1], (unsigned int)ft_atoi_simple(s2), dest));
		i++;
	}
}

size_t		accuracy(const char *s1, size_t i)
{
	size_t	acc;

	acc = 0;
	while(s1[i] >= '0' && s1[i] <= '9')
		acc = ft_atoi_simple(&s1[i]);
	if (s1[i] == '*')
		acc = ft_atoi_simple(v[2]);
	return (acc);
}

size_t		width(const char *s1, size_t i)
{
	size_t	len;

	len = 0;
	if (s1[i++] == '.')
	{
		while(s1[i] >= '0' && s1[i] <= '9')
			len = ft_atoi_simple(&s1[i]);
		if (s1[i] == '*')
		len = ft_atoi_simple(v[3]);
	}
	return (len);
}