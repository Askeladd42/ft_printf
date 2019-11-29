# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 10:15:47 by plam              #+#    #+#              #
#    Updated: 2019/11/19 10:33:42 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		+=	-Wall -Wextra -Werror -I libftprintf.h

all:		$(NAME)

$(NAME):	${OBJS}
			ar rcs $(NAME) ${OBJS}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} $(NAME)

re :		fclean all
