/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:23:47 by plam              #+#    #+#             */
/*   Updated: 2020/02/14 13:50:45 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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

char	*conv(int hex, t_print *dest)
{
	char	*disp;

	disp = NULL;
	if (dest->cnv & INTEGER)
		disp = ft_itoa_ult(hex, "0123456789", dest);
	else if (dest->cnv & CHARACTER)
	{
		*disp++ = hex;
		*disp = '\0';
	}
	return (disp);
}

char	*uns_conv(unsigned int hex, t_print *dest)
{
	char	*disp;

	disp = NULL;
	if (dest->cnv & U_INTEGER)
		disp = ft_utoa_ult(hex, "0123456789", dest);
	else if (dest->cnv & L_HEX || dest->cnv & ADDRESS)
	{
		if (dest->cnv & ADDRESS)
			ft_putstr("0x7ffe");
		disp = ft_utoa_ult(hex, "0123456789abcdef", dest);
	}
	else if (dest->cnv & H_HEX)
		disp = ft_utoa_ult(hex, "0123456789ABCDEF", dest);
	return (disp);
}
