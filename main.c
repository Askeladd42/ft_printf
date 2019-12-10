/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2019/12/10 14:57:31 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(int c, char **v)
{
	if (c > 1)
	{
		//printf("bruh %-10.7d\n", 1001);
		//printf("%s\n", ft_itoa_ult(42, "0123456789ABCDEF"));
		printf("OG Printf = %s\n", v[2]);
		//printf("Mine = %s\n", uns_conv(v[1], atoi(v[2])));
		//printf("OG Printf = %X\n", atoi(v[2]));
		ft_putstr("Mine = ");
		parsing_path(v[1], v[2]);
		printf("\n");
	}
	return (0);
}
