# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bryaloo <bryaloo@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 19:39:01 by bryaloo           #+#    #+#              #
#    Updated: 2024/04/22 19:39:56 by bryaloo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT	= ./libft/

LIBFT_A = ./libft/libft.a

SRCS	=	ft_printf.c \
			print_char.c \
			print_hex.c \
			print_nbr.c \
			print_percent.c \
			print_ptr.c \
			print_str.c \
			print_unsigned.c

AR		= ar rcs

RM		= rm -f

GCC		= gcc

CFLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${GCC} ${CFLAGS} -g -c $< -o $@

${NAME}:	${OBJS}
			make -C ${LIBFT}
			cp ${LIBFT_A} ${NAME}
			${AR} ${NAME} ${OBJS}

clean:
	make clean -C ${LIBFT}
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
