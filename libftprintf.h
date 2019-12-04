/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:27:09 by plam              #+#    #+#             */
/*   Updated: 2019/12/04 13:58:19 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t			ft_strlen(char *str);
void			ft_putstr(char *s);
char			*ft_itoa_ult(int n, char *charset);
char			*ft_utoa_ult(unsigned int n, char *charset);
size_t			stringer(const char *format);
char			*conv(char *offset, int hex);
char			*uns_conv(char *offset, unsigned int hex);
void			flag_checker(char *str);

#endif
