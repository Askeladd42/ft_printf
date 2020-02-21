/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2020/02/21 20:36:35 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{

	/*int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";*/
	
	/*ft_printf("\tft : %d\n", ft_printf("%0*d\n", 20, 200502));
	printf("\tOG : %d\n", printf("%0*d\n", 20, 200502));*/

	ft_printf("\tft : %d\n", ft_printf("%0*i", 8, -54));
	printf("\tOG : %d\n", printf("%0*i", 8, -54));


/*	ft_printf("\tft : %d\n", ft_printf("%0*x\n", 9000 ,42252));
	printf("\tOG : %d\n", printf("%0*x\n", 9000, 42252));
*/

/*	ft_printf("\tft : %d\n", ft_printf("zoozie, %-*.s\n", 0, "endgame"));
	printf("\tOG : %d\n", printf("zoozie, %-*.s\n", 0, "endgame"));*/

	/*int c = 45;
	char *s = NULL;
	unsigned int i = 12589;
	printf("OG : c = %p\n\n", &c);
	ft_printf("ft : c = %p\n\n", &c);
	printf("%i\n", printf("%p\n", &s));
	ft_printf("%i\n", ft_printf("%p\n", &s));
	printf("%i\n", printf("%u\n", i));
	ft_printf("%i\n", ft_printf("%u\n", i));*/

	/*printf("|%*.*i|\n", -1, -12, 758);
	ft_printf("ft_printf = %i\n", ft_printf("|^.^/%*.*s^.^/|\n", -85, -8, s));
	printf("OG printf = %i\n", printf("|^.^/%*.*s^.^/|\n", -85, -8, s));
	printf("OG printf = %i\n", printf("|^.^/%*.*s^.^/|\n", -85, -8, s));
	printf("%p\n", &s);
	ft_printf("|%10.6x|\n", 46654);*/

	/*ft_printf("%p\n", &c);
	ft_printf("%i", ft_printf("\\!/%.p\\!/\n", s));
	printf("%i", printf("\\!/%.p\\!/\n", s));
	printf("\n\n");
	printf("%-7.1s\n", s);
	ft_printf("%-7.1s\n", s);*/
	
	/*ft_printf("%i", ft_printf("\\!/42%19.30s42\\!/\n", "4560635760"));
	printf("%i", printf("\\!/42%19.30s42\\!/\n", "4560635760"));*/
	
	/*printf("i = %d\n",printf("%%d%%%*s%%", 5, "hi"));
	ft_printf("i = %d\n",ft_printf("%%d%%%*s%%\n", 5, "hi"));*/

	/*ft_printf("%%%d%c%d%i%u%x%%%X", 45, 'd', 242, 54545, -53424345, i, i);
	printf("\n\n\n");
	printf("%%%d%c%d%i%u%x%%%X", 45,'d', 242, 54545, -53424345, i, i);
	printf("%%%d%p%s%c%d%i%u%x%%%X", 45, &c, "HELLOOOOLJLJL<<", 'd', 242, 54545, -53424345, i, i);
	printf("\n\n\n");
	ft_printf("%%%d%p%s%c%d%i%u%x%%%X", 45, &c, "HELLOOOOLJLJL<<", 'd', 242, 54545, -53424345, i, i);*/
	
	
	/*ft_printf("go of %3.2s\n", NULL);
	int p = printf("OG Printf = %8.3i\n", -8473);
	int fp = ft_printf("ft_printf = %8.3i\n", -8473);
	printf("OG Printf count = %i\nft_printf count = %i\n", p, fp);*/
	return (0);
}
