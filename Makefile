# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 11:51:52 by dbenkhar          #+#    #+#              #
#    Updated: 2021/10/25 17:33:40 by dbenkhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c srcs/ft_init.c srcs/ft_ptr.c srcs/ft_printf_char.c\
		srcs/ft_printf_int.c srcs/ft_printf_lohex.c srcs/ft_printf_str.c\
		srcs/ft_printf_strdup.c srcs/ft_printf_uint.c srcs/ft_printf_uphex.c

OBJS	= ${SRCS:.c=.o}

CC	= gcc
RM 	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all