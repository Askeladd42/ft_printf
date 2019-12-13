/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:23:47 by plam              #+#    #+#             */
/*   Updated: 2019/12/13 17:23:34 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*size_t	stringer(const char *format)
{
	size_t	i;

	i = 0;
	while (format[i] != '%' && format[i])
	{
		if (format[i] == '\\')
		{
			i++;
			if (format[i] == 'n')
			{
				write(1, "\n", 1);
				i++;
			}
		}
		write(1, &format[i++], 1);
	}
	return (i);
}
*/
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

char	*conv(const char *offset, int hex)
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
			disp = ft_itoa_ult(hex, "0123456789");
		if (offset[i + 1] == 'c')
			write(1, &hex, 1);
	return (disp);
}

char	*uns_conv(const char *offset, unsigned int hex)
{
	size_t	i;
	size_t	len;
	size_t	acc;
	char	*disp;

	i = 0;
	len = 0;
	acc = 0;
	disp = NULL;
	if (offset[i] == '%')
	{
		//flag_checker(&offset[i], len, acc);
		if (offset[i + 1] == 'u')
			disp = ft_utoa_ult(hex, "0123456789");
		else if (offset[i + 1] == 'x' || offset[i + 1] == 'p')
			disp = ft_utoa_ult(hex, "0123456789abcdef");
			if (offset[i + 1] == 'p')
				write(1, "0x", 2);
		else if (offset[i + 1] == 'X')
			disp = ft_utoa_ult(hex, "0123456789ABCDEF");
	}
	return (disp);
}

/*void	flag_checker(char *str, size_t len, size_t acc)// à réduire (29 lignes)
{
	int		i;
	char	*get;

	i = 0;
	len = 0;
	acc = 0;
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
*/