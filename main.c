/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2020/02/17 16:39:34 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	//int c = 45;
	//char *s = "HELLO";
	unsigned int i = 12589;
	/*printf("OG : c = %p\n\n", &c);
	ft_printf("ft : c = %p\n\n", &c);
	printf("%i\n", printf("%p\n", &s));
	ft_printf("%i\n", ft_printf("%p\n", &s));
	printf("%i\n", printf("%u\n", i));
	ft_printf("%i\n", ft_printf("%u\n", i));*/

	/*printf("|%*.*i|\n", -1, -12, 758);
	ft_printf("ft_printf = %i\n", ft_printf("|^.^/%*.*d^.^/|\n", -85, -8, c));
	printf("OG printf = %i\n", printf("|^.^/%*.*d^.^/|\n", -85, -8, c));
	printf("%p\n", &s);
	ft_printf("|%10.6x|\n", 46654);*/

	/*ft_printf("%p", &c);*/
	/*printf("%-.8s", "HELLOOOOLJLJL<<\n");
	ft_printf("%-8s", "HELLOOOOLJLJL<<\n");*/
	//printf("\n\n");
	/*printf("%-7.1s", s);
	ft_printf("%-7.1s", s);*/
	
	
	ft_printf("%%%d%c%d%i%u%x%%%X", 45, 'd', 242, 54545, -53424345, i, i);
	printf("\n\n\n");
	printf("%%%d%c%d%i%u%x%%%X", 45,'d', 242, 54545, -53424345, i, i);
	/*printf("%%%d%p%s%c%d%i%u%x%%%X", 45, &c, "HELLOOOOLJLJL<<", 'd', 242, 54545, -53424345, i, i);
	printf("\n\n\n");
	ft_printf("%%%d%p%s%c%d%i%u%x%%%X", 45, &c, "HELLOOOOLJLJL<<", 'd', 242, 54545, -53424345, i, i);*/
	
	
	//ft_printf("go of %3.2s\n", NULL);
	/*int p = printf("OG Printf = %8.3i\n", -8473);
	int fp = ft_printf("ft_printf = %8.3i\n", -8473);
	printf("OG Printf count = %i\nft_printf count = %i\n", p, fp);*/
	return (0);
}
