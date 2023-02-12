# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:23:16 by rmouhoub          #+#    #+#              #
#    Updated: 2023/02/12 13:57:21 by rmouhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

DIR_SRCS		=	srcs
DIR_ALGO		=	algo
DIR_PARSER		=	parser
DIR_MOVS		=	mouvments
DIR_OBJS		=	objs

SRCS 		= 	$(DIR_ALGO)/stack_3.c \
				$(DIR_ALGO)/do_up_down.c \
				$(DIR_ALGO)/algo.c \
				$(DIR_ALGO)/utils.c \
				$(DIR_ALGO)/costs.c \
				$(DIR_PARSER)/parser.c \
				$(DIR_PARSER)/parser2.c \
				$(DIR_MOVS)/movs.c \
				$(DIR_MOVS)/p_a_b.c \
				$(DIR_MOVS)/r_a_b.c \
				$(DIR_MOVS)/s_a_b.c \

CFLAGS		= -Wall -Werror -Wextra -g3
CC			= cc
BUILD_DIR 	= .build
INCLUDES	= includes 
LIBFT		= libft
OBJS		= $(SRCS:%.c=$(DIR_OBJS)/%.o)
SRCS		:= $(SRCS:%=$(DIR_SRCS)/%)


all			: ${NAME}

${NAME}		: ${OBJS}
		make -C libft
		${CC} $(OBJS) -o $(NAME) -L./libft/ -lft

${DIR_OBJS}/%.o:%.c
		${CC} ${CFLAGS} -I ${INCLUDES} -I ${LIBFT} -c $< -o $@

clean :
		make -C ./libft/ clean

fclean : clean
		rm -rf ${NAME} libft/libft.a

re : fclean all