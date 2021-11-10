# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 14:52:42 by lpascrea          #+#    #+#              #
#    Updated: 2021/11/10 14:33:48 by lpascrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS#
_END	= \033[0m
_GREEN	= \033[0;32m
_RED	= \033[0;31m
_BLUE	= \033[0;96m
_YELLOW	= \033[0;33m
_MAG 	= \033[0;35m
#------#

SRCS		=	philo.c \
				./errors/error.c \
				./srcs/args.c \
				./srcs/utils.c \
				./srcs/init.c \
				./srcs/free.c \
				./thread/philo_thread.c \
				./thread/actions.c \
				./thread/died.c \

OBJS		=	${SRCS:.c=.o}

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

NAME		=	philo

all:		${NAME}
			@echo "$(_GREEN)Philo is ready $(_END)"

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -pthread -I. -o ${NAME}

%.o:		%.c
			${CC} -o $@ -c $< -I.

clean:
			${RM} ${OBJS}
			@echo "$(_YELLOW)\".o\" files deleted $(_END)"

fclean:		clean
			${RM} ${NAME}
			@echo "$(_RED)Philo cleaned $(_END)"

re:			fclean all

.PHONY:		all clean fclean re