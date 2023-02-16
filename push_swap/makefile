# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:23:16 by rmouhoub          #+#    #+#              #
#    Updated: 2023/02/16 19:31:20 by rmouhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

DIR_SRCS		=	srcs
DIR_ALGO		=	algo
DIR_PARSER		=	parser
DIR_MOVS		=	mouvments
DIR_OBJS		=	objs
DIR_CHECK		=	checker
DIR_CHECKK		=	checkerr


SRCS 		= 	$(DIR_ALGO)/stack_3.c \
				$(DIR_ALGO)/do_up_down.c \
				$(DIR_ALGO)/algo.c \
				$(DIR_ALGO)/utils.c \
				$(DIR_ALGO)/utils2.c \
				$(DIR_ALGO)/utils3.c \
				$(DIR_ALGO)/costs.c \
				$(DIR_PARSER)/parser.c \
				$(DIR_PARSER)/parser2.c \
				$(DIR_MOVS)/movs.c \
				$(DIR_MOVS)/p_a_b.c \
				$(DIR_MOVS)/r_a_b.c \
				$(DIR_MOVS)/s_a_b.c \

BONUS		=	$(DIR_CHECKK)/mychecker.c \
				$(DIR_ALGO)/stack_3.c \
				$(DIR_ALGO)/do_up_down.c \
				$(DIR_ALGO)/algo.c \
				$(DIR_ALGO)/utils.c \
				$(DIR_ALGO)/utils2.c \
				$(DIR_ALGO)/utils3.c \
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
OBJS_B		= $(BONUS:%.c=$(DIR_OBJS)/%.o)
SRCS		:= $(SRCS:%=$(DIR_SRCS)/%)
BONUS		:= $(BONUS:%=$(DIR_CHECK)/%)

all			: ${NAME}
bonus		: ${NAME_BONUS}

${NAME}		: ${OBJS}
		make -C libft
		${CC} $(OBJS) -o $(NAME) -L./libft/ -lft

${NAME_BONUS}: ${OBJS_B}
		make -C libft
		${CC} $(OBJS_B) -o $(NAME_BONUS) -L./libft/ -lft

${DIR_OBJS}/%.o:%.c
		${CC} ${CFLAGS} -I ${INCLUDES} -I ${LIBFT} -c $< -o $@

clean :
		make -C ./libft/ clean

fclean : clean
		rm -rf ${NAME} libft/libft.a ${NAME} ${NAME_BONUS} push_swap/checker push_swap/push_swap

re : fclean all