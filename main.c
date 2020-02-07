/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:20:20 by plam              #+#    #+#             */
/*   Updated: 2020/02/07 11:10:14 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	printf("* OG Printf = Bonjour les gens,\nbonjour %-p,\ncomment allez-vous ?\n%15.8s\nSuper !", "git gud", "Plutot bien.");
	ft_printf("* ft_printf = Bonjour les gens,\nbonjour %-p,\ncomment allez-vous ?\n%15.8s\nSuper !", "git gud", "Plutot bien.");
	return (0);

}
