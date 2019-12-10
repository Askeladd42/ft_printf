/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:27:09 by plam              #+#    #+#             */
/*   Updated: 2019/12/10 14:56:55 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define BUFFER_SIZE 64

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_list
{
	va_list		buff[BUFFER_SIZE + 1];
	int			flag;
}				t_print;

// structure pour faire fonctionner toutes les fonctions ensemble à faire
// utiliser va_arg(ap, ...) avec les fonctions de conversion pour les faire tourner
// ATTENTION ! entier precision a toujours un 0 en premieer lieu !

size_t			ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_itoa_ult(int n, char *charset);
char			*ft_utoa_ult(unsigned int n, char *charset);
size_t			stringer(const char *format);
char			*conv(char *offset, int hex);
char			*uns_conv(char *offset, unsigned int hex);
void			flag_checker(char *str, size_t len, size_t	acc);
void			parsing_path(const char *s1, const char *s2);
void			parse_print(const char *s1, const char *s2, size_t i);
int				ft_printf(const char *format, ...);
#endif
