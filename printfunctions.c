/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:23:47 by plam              #+#    #+#             */
/*   Updated: 2020/01/05 14:49:52 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

char	*uns_conv(const char *offset, unsigned int hex, size_t acc, t_print dest)
{
	size_t	i;
	size_t	len;
	char	*disp;

	i = 0;
	len = acc;
	disp = NULL;
	if (offset[i] == '%')
	{
		if (offset[i + 1] == 'u')
			disp = ft_utoa_ult(hex, "0123456789", dest);
		else if (offset[i + 1] == 'x' || offset[i + 1] == 'p')
			disp = ft_utoa_ult(hex, "0123456789abcdef", dest);
			if (offset[i + 1] == 'p')
				write(1, "0x", 2);
		else if (offset[i + 1] == 'X')
			disp = ft_utoa_ult(hex, "0123456789ABCDEF", dest);
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
	ft_putstr(&str[i]);
	get = &str[i];
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
	if (get[i] == '*')
		//on passe à l'argument suivant, qui prend la place de l' *
	if (get[i] >= '0' && get[i] <= '9')
	{
		len = ft_atoi_simple(&get[i]);
		i++;
	}
	if (get[i] == '*' && get[i - 1] == '.')
		//on passe à l'argument suivant, qui prend la place de l' * s'il est un int
	if ((get[i] >= '0' && get[i] <= '9') && get[i - 1] == '.')
	{
		acc = ft_atoi_simple(&get[i]);
		i++;
	}
	len = (acc >= len) ? acc : len - acc;
}
*/
