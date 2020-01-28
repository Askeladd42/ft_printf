/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2020/01/28 17:23:20 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	//printf("bruh %-10.7d\n", 1001);
	printf("* OG Printf = Bonjour les gens,\nbonjour %-*.*i,\ncomment allez-vous ?\n", 8, 3, -42);
	ft_printf("* ft_printf = Bonjour les gens,\nbonjour %-*.*i,\ncomment allez-vous ?\n", 8, 3, -42);
	return (0);
}
