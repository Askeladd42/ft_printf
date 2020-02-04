# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 10:15:47 by plam              #+#    #+#              #
#    Updated: 2020/02/04 16:24:06 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_strlen.c parsing.c\
				ft_putstr.c set_func.c\
				ft_printf.c buffer_util.c \
				ft_itoa_ult.c printfunctions.c \

SRC			= $(addprefix ./srcs/, $(SRCS))

OBJS		= 	${SRC:.c=.o}

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