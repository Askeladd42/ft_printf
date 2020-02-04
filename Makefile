# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 10:15:47 by plam              #+#    #+#              #
#    Updated: 2020/02/04 16:02:06 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	./srcs/ft_strlen.c ./srcs/parsing.c\
				./srcs/ft_putstr.c ./srcs/set_func.c\
				./srcs/ft_printf.c ./srcs/buffer_util.c \
				./srcs/ft_itoa_ult.c ./srcs/printfunctions.c \

OBJS		= 	${SRCS:.c=.o}

NAME		= 	libftprintf.a

CC			= 	gcc

RM			= 	rm -f

CFLAGS		+=	-Wall -Wextra -Werror -I ./includes/libftprintf.h

all:		$(NAME)

$(NAME):	${OBJS}
			ar rcs $(NAME) ${OBJS}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} $(NAME)

re :		fclean all
