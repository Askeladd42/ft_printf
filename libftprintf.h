/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:27:09 by plam              #+#    #+#             */
/*   Updated: 2019/12/08 12:51:09 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// structure pour faire fonctionner toutes les fonctions ensemble à faire

size_t			ft_strlen(char *str);
void			ft_putstr(char *s);
char			*ft_itoa_ult(int n, char *charset);
char			*ft_utoa_ult(unsigned int n, char *charset);
size_t			stringer(const char *format);
char			*conv(char *offset, int hex);
char			*uns_conv(char *offset, unsigned int hex);
void			flag_checker(char *str, size_t len, size_t	acc);
void			parsing_path(const char *s, va_list ap);
void			parsing_path_extra(const char *s, va_list ap);
int				ft_printf(const char *format, ...);
#endif
