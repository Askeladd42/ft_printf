/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:23:47 by plam              #+#    #+#             */
/*   Updated: 2020/01/13 18:14:55 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == c)
		return ((char *)&str[i]);
	return (0);
}

int		ft_atoi_simple(const char *str)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		t = t * 10 + (str[i] - '0');
		i++;
	}
	return (t);
}

char	*conv(const char *offset, int hex, t_print dest)
{
	size_t	i;
	size_t	len;
	size_t	acc;
	char	*disp;

	i = 0;
	disp = NULL;
	len = 0;
	acc = 0;
	if (offset[i] == '%')
		//flag_checker(&offset[i], len, acc);
		if (offset[i + 1] == '%')
			disp = "%";
		if (offset[i + 1] == 'd' || offset[i + 1] == 'i')
			disp = ft_itoa_ult(hex, "0123456789", dest);
		if (offset[i + 1] == 'c')
			write(1, &hex, 1);
	return (disp);
}

char	*uns_conv(const char *offset, unsigned int hex, t_print dest)
{
	size_t	i;
	size_t	len;
	char	*disp;

	i = 0;
	disp = NULL;
	if (offset[i] == '%')
	{
		if (offset[i + 1] == 'u')
			disp = ft_utoa_ult(hex, "0123456789", dest);
		else if (offset[i + 1] == 'x' || offset[i + 1] == 'p')
			disp = ft_utoa_ult(hex, "0123456789abcdef", dest);
		else if (offset[i + 1] == 'X')
			disp = ft_utoa_ult(hex, "0123456789ABCDEF", dest);
	}
	return (disp);
}