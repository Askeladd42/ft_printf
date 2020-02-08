/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2020/02/08 16:05:26 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	/*int p = printf("* OG Printf = Bonjour les gens,\nbonjour %-p,\ncomment allez-vous ?\n%15.8s\nSuper !", "789644", "Plutot bien.");
	int fp = ft_printf("* ft_printf = Bonjour les gens,\nbonjour %-p,\ncomment allez-vous ?\n%15.8s\nSuper !", "789644", "Plutot bien.");
	printf("\n\n\nprintf return = %i\nft_printf return = %i\n", p, fp);*/
	printf("OG Printf = %8.3i\n", -8473);
	ft_printf("ft_printf = %8.3i\n", -8473);
	return (0);
}
