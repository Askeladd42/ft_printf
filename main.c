/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2019/12/07 13:03:03 by plam             ###   ########.fr       */
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
		ft_putstr("Mine = ");
		ft_putstr(conv(v[1],atoi(v[2])));
		printf("\n");
		printf("OG Printf = %c\n", atoi(v[2]));
		//printf("Mine = %s\n", uns_conv(v[1], atoi(v[2])));
		//printf("OG Printf = %X\n", atoi(v[2]));
	}
	return (0);
}
