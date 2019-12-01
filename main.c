/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2019/12/01 12:35:00 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(int c, char **v)
{
	if (c > 1)
	{
		printf("%p\n", 256);
		printf("%s\n", ft_itoa_ult(42, "0123456789ABCDEF"));
		conv(v[1], atoi(v[2]));
		printf("OG Printf = %p\n", atoi(v[2]));
		uns_conv(v[1], atoi(v[2]));
		printf("OG Printf = %X\n", atoi(v[2]));
	}
	return (0);
}
