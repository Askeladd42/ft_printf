/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:27:09 by plam              #+#    #+#             */
/*   Updated: 2019/12/13 15:51:38 by plam             ###   ########.fr       */
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
	char		buff[BUFFER_SIZE];
	size_t		index;
	size_t		size;
}				t_print;

// structure pour faire fonctionner toutes les fonctions ensemble à faire
// utiliser va_arg(ap, ...) avec les fonctions de conversion pour les faire tourner
// ATTENTION ! entier precision a toujours un 0 en premieer lieu !
//Ré-adapter les convertisseurs avec un buffer, donc sans malloc !

size_t			ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
char			*ft_itoa_ult(int n, char *charset);
char			*ft_utoa_ult(unsigned int n, char *charset);
size_t			stringer(const char *format);
char			*conv(const char *offset, int hex);
char			*uns_conv(const char *offset, unsigned int hex);
void			flag_checker(char *str, size_t len, size_t	acc);
void			parsing_path(const char *s1, const char *s2);
void			parse_print(const char *s1, const char *s2, size_t i);
int				ft_atoi_simple(const char *str);
int				ft_printf(const char *format, ...);
#endif
