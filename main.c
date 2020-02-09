/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2020/02/09 13:53:03 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	//printf("* OG Printf = Bonjour les gens,\nbonjour %-8p,\ncomment allez-vous ?\n%15.10s\nSuper !", "-789644", "Plutot bien.");
	printf("\n");
	ft_printf("* ft_printf = Bonjour les gens,\nbonjour %-8p,\ncomment allez-vous ?\n%15.10s\nSuper !", "-789644", "Plutot bien.");
	//ft_printf("go of %3.2s\n", NULL);
	/*int p = printf("OG Printf = %8.3i\n", -8473);
	int fp = ft_printf("ft_printf = %8.3i\n", -8473);
	printf("OG Printf count = %i\nft_printf count = %i\n", p, fp);*/
	return (0);
}
