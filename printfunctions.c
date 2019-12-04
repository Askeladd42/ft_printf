/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:23:47 by plam              #+#    #+#             */
/*   Updated: 2019/12/04 14:37:36 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	stringer(const char *format)
{
	size_t	i;

	i = 0;
	while (format[i] != '%' && format[i])
		write(1, &format[i++], 1);
	return (i);
}

int		ft_atoi_simple(char *str)
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

char	*conv(char *offset, int hex)
{
	size_t	i;
	char	*disp;

	i = 0;
	disp = NULL;
	if (offset[i] == '%')
		if (offset[i + 1] == '%')
			disp = "%";
		else if (offset[i + 1] == 'd' || offset[i + 1] == 'i')
			disp = ft_itoa_ult(hex, "0123456789");
	return (disp);
}

char	*uns_conv(char *offset, unsigned int hex)
{
	size_t	i;
	char	*disp;

	i = 0;
	disp = NULL;
	if (offset[i] == '%')
	{
		flag_checker(&offset[i]);
		if (offset[i + 1] == '%')
			disp = "%";
		else if (offset[i + 1] == 'u')
			disp = ft_utoa_ult(hex, "0123456789");
		else if (offset[i + 1] == 'x')
			disp = ft_utoa_ult(hex, "0123456789abcdef");
		else if (offset[i + 1] == 'X')
			disp = ft_utoa_ult(hex, "0123456789ABCDEF");
		else if (offset[i + 1] == 'p')
		{
			disp = ft_utoa_ult(hex, "0123456789abcdef");
			write(1, "0x", 2);
		}
	}
	return (disp);
}

void	flag_checker(char *str)// à réduire
{
	int		i;
	int		len;
	int		acc;
	char	*get;

	i = 0;
	get = &str[stringer(str)];
	if (get[i] == '-')
	{
		//set_spaces(get);
		i++;
	}
	if (get[i] == '0')
	{
		if (get[i - 1] == '-')
			i++;
		//set_zeros(get);
	}
	if (get[i] >= '0' && get[i] <= '9')
	{
		len = ft_atoi_simple(&get[i]);
		i++;
	}
	if ((get[i] >= '0' && get[i] <= '9') && get[i - 1] == '.')
	{
		acc = ft_atoi_simple(&get[i]);
		i++;
	}
	len = (acc >= len) ? acc : len - acc;
}