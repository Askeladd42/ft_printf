/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:27:09 by plam              #+#    #+#             */
/*   Updated: 2020/01/14 14:23:16 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define BUFFER_SIZE 64

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_list
{
	char		buff[BUFFER_SIZE];
	size_t		index;
	size_t		size;
	size_t		acc;
	int			flags;
	int			cnv;
}				t_print;

typedef enum	s_flags
{
	ZEROS		= (1U), 
	MINUS 		= (1U << 1U),
	L_ASTERISK 	= (1U << 2U),
	POINT 		= (1U << 3U),
	R_ASTERISK 	= (1U << 4U),
}				t_flags;

typedef enum	s_conv
{
	CHARACTER 	= (1U),
	STRING 		= (1U << 1U),
	ADDRESS 	= (1U << 2U),
	INTEGER 	= (1U << 3U),
	U_INTEGER 	= (1U << 4U),
	L_HEX 		= (1U << 5U),
	H_HEX 		= (1U << 6U),
}				t_conv;

// structure pour faire fonctionner toutes les fonctions ensemble à faire
// utiliser va_arg(ap, ...) avec les fonctions de conversion pour les faire tourner
// ATTENTION ! entier precision a toujours un 0 en premier lieu !

size_t			ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
char			*ft_itoa_ult(int n, char *charset, t_print dest);
char			*ft_utoa_ult(unsigned int n, char *charset, t_print dest);
char			*ft_strchr(const char *s, int c);
size_t			stringer(const char *format);
size_t			accuracy(const char *s1, size_t i, const char **v);
size_t			width(const char *s1, size_t i, const char **v);
char			*conv(const char *offset, int hex, t_print dest);
char			*uns_conv(const char *offset, unsigned int hex, t_print dest);
void			flag_checker(const char *str, size_t len, size_t	acc);
void			parsing_path(const char *s1, const char **v);
void			parse_print(const char *s1, const char *s2, size_t i);
int				ft_atoi_simple(const char *str);
int				ft_printf(const char *format, ...);
void			set_spaces(char *get, size_t i, size_t len, size_t acc);
void			set_zeros(char *get, size_t len, size_t acc);
void			toggling_flag(char c, t_print printer,  va_list ap);
void			flag_parser(t_print printer, const char *fmt, va_list ap);
void			converter(char c, t_print printer);
void			print_converter(t_print printer, va_list ap);
#endif
