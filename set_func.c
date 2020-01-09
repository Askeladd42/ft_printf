/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:33:24 by plam              #+#    #+#             */
/*   Updated: 2020/01/09 11:28:37 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		accuracy(const char *s1, size_t i, const char **v)
{
	size_t	acc;

	acc = 0;
	if (s1[i] == '.')
	{
		if (s1[++i] >= '0' && s1[++i] <= '9')
			acc = (unsigned int)ft_atoi_simple(&s1[i]);
		if (s1[++i] == '*')
			acc = (unsigned int)ft_atoi_simple(v[3]);
	}
	i++;
	return (acc);
}

size_t		width(const char *s1, size_t i, const char **v)
{
	size_t	len;

	len = 0;
	if (s1[i] >= '0' && s1[i] <= '9')
		len = (unsigned int)ft_atoi_simple(&s1[i]);
	if (s1[i] == '*')
		len = (unsigned int)ft_atoi_simple(v[2]);
	i++;
	return (len);
}

/*void	set_spaces(char *get, size_t i, size_t len, size_t acc)
{
	if (acc >= len)
	{
		while (i < acc - ft_strlen(conv(&get[i])))
			ft_putchar('0');
			i++;
	}
	else if (len > acc)
		i++;
}

void	set_zeros(char *get, size_t i, size_t len, size_t acc)
{
	if (get[i + 1] == '0')
	{
		len = width(s1, i++, v);
		acc = accuracy(s1, i++, v);
		i++;
		set_sp = (len - acc > 0 ? len - acc : 0);
	}
}
*/