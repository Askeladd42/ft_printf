/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2020/02/03 17:09:23 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	printf("* OG Printf = Bonjour les gens,\nbonjour %-*.*u,\ncomment allez-vous ?\n%.8s\nSuper !", 8, 18, 846, "Plutot bien.");
	ft_printf("* ft_printf = Bonjour les gens,\nbonjour %-*.*u,\ncomment allez-vous ?\n%.8s\nSuper !", 8, 18, 846, "Plutot bien.");
	return (0);

}
