# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:23:16 by rmouhoub          #+#    #+#              #
#    Updated: 2023/02/18 12:08:26 by rmouhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

LIBFT			= libft.a

DIR_SRCS		=	srcs/mandatory
DIR_BONUS		=	srcs/bonus
DIR_OBJS		=	objs

DIR_ALGO		=	algo
DIR_PARSER		=	parser
DIR_MOVS		=	mouvments
DIR_CHECK		=	checker
DIR_CHECKK		=	checkerr


SRCS_NAMES 		= 	$(DIR_ALGO)/stack_3.c \
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

SRCS_NAMES_B	=	$(DIR_CHECKK)/mychecker.c \
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

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))
SRCS_B			=	$(addprefix $(DIR_BONUS)/,$(SRCS_NAMES_B))
OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))


CFLAGS		= -Wall -Werror -Wextra -g3

CC			= cc

HEAD		= -Iincludes -Ilibft 

all				:	${NAME}

$(NAME): $(OBJS)
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT} -o $(NAME)
	@echo "\033[34;5mpushswap\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p objs/algo
	mkdir -p objs/parser
	mkdir -p objs/mouvments
	mkdir -p objs/checker
	mkdir -p objs/checkerr

bonus:
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(SRCS_B) ${HEAD} ${LIBFT} -o $(NAME_BONUS)
	@echo "\033[31;5mpushswap BONUS\033[0m"


clean :
		make clean -C libft
		rm -rf ${DIR_OBJS}
		rm -rf ${OBJS}
		rm -rf libft.a
		rm -rf push_swap
		rm -rf checker

fclean : clean
		rm -rf ${NAME}

re : fclean all