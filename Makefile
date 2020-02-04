# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 10:15:47 by plam              #+#    #+#              #
#    Updated: 2020/02/04 14:21:24 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	buffer_util.c set_func.c printfunctions.c \
				ft_strlen.c ft_itoa_ult.c ft_printf.c parsing.c\
				ft_putstr.c \
				
OBJS		= 	srcs/${SRCS:.c=.o}

NAME		= 	libftprintf.a

CC			= 	gcc

RM			= 	rm -f

CFLAGS		+=	-Wall -Wextra -Werror -I includes/libftprintf.h

all:		$(NAME)

$(NAME):	${OBJS}
			ar rcs $(NAME) ${OBJS}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} $(NAME)

re :		fclean all
