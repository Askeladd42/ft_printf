/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:27:09 by plam              #+#    #+#             */
/*   Updated: 2020/02/09 10:48:48 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define BUFFER_SIZE 8192

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_list
{
	char			buff[BUFFER_SIZE];
	size_t			index;
	size_t			size;
	int				acc;
	unsigned int	flags;
	unsigned int	cnv;
}					t_print;

typedef enum		e_flags
{
	ZEROS = (1U),
	MINUS = (1U << 1U),
	L_ASTERISK = (1U << 2U),
	POINT = (1U << 3U),
	R_ASTERISK = (1U << 4U),
}					t_flags;

typedef enum		e_conv
{
	CHARACTER = (1U),
	STRING = (1U << 1U),
	ADDRESS = (1U << 2U),
	INTEGER = (1U << 3U),
	U_INTEGER = (1U << 4U),
	L_HEX = (1U << 5U),
	H_HEX = (1U << 6U),
	PERCENT = (1U << 7U),
}					t_conv;

void				ft_putchar(char c);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(char *str);
void				ft_putstr(const char *s);
char				*ft_itoa_ult(int n, char *charset, t_print *dest);
char				*ft_utoa_ult(unsigned int n, char *charset, t_print *dest);
char				*conv(int hex, t_print *dest);
char				*uns_conv(unsigned int hex, t_print *dest);
char				*ft_strchr(const char *s, int c);
size_t				passing_nb(const char *fmt, size_t i);
int					accuracy(const char *fmt, size_t i, t_print *printer);
size_t				width(const char *fmt, size_t i, t_print *printer);
int					ft_atoi_simple(const char *str);
int					ft_printf(const char *format, ...);
size_t				set_spaces(t_print *printer);
size_t				set_zeros(t_print *printer);
size_t				len_add(t_print *printer);
void				toggling_flag(char c, t_print *printer, va_list ap);
size_t				flag_parser(t_print *printer, const char *fmt, va_list ap,
								size_t i);
void				converter(char c, t_print *printer);
void				print_converter(t_print *printer, va_list ap);
void				buffer_register(t_print *printer);
void				total_print(t_print *printer, va_list ap);
#endif