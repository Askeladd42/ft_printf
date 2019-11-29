/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:27:09 by plam              #+#    #+#             */
/*   Updated: 2019/11/19 13:59:20 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


int	ft_strlen(const char *format);
int	ft_itoa_base(const char *format, char *charset);
int	stringer(const char *format);

#endif
