/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:33:24 by plam              #+#    #+#             */
/*   Updated: 2019/12/15 14:43:22 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_spaces(char *get, size_t i, size_t len, size_t acc)
{
	if (acc >= len)
	{
		while (i < acc - ft_strlen(conv(&get[i])))
			ft_putchar('0');
			i++;
	}
	else if (len > acc)
		i++;
	// convertir les nombres de telle sorte que flag_checker soit respecté
}

void	set_zeros(char *get, size_t len, size_t acc)
{
	if (get[i + 1] == '0')
	// convertir les nombres de telle sorte que flag_checker soit respecté
}