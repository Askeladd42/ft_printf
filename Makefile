# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 10:15:47 by plam              #+#    #+#              #
#    Updated: 2020/01/16 10:50:11 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_strlen.c ft_itoa_ult.c ft_printf.c \
				ft_putstr.c printfunctions.c parsing.c \
				
OBJS		= 	${SRCS:.c=.o}

NAME		= 	libftprintf.a

CC			= 	gcc

RM			= 	rm -f

CFLAGS		+=	-Wall -Wextra -Werror -I libftprintf.h

all:		$(NAME)

$(NAME):	${OBJS}
			ar rcs $(NAME) ${OBJS}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} $(NAME)

re :		fclean all
