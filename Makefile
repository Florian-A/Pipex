# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:33:02 by f██████           #+#    #+#              #
#    Updated: 2022/04/09 17:02:53 by f██████          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC_DIR	= ./sources
INC_DIR	= ./includes
NAME	= pipex
NAME_BONUS = pipex_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address
HEADER_FILE	= $(INC_DIR)/pipex.h
LIBFT_PATH	= ./libft/libft.a

SRCS = $(addprefix $(SRC_DIR)/, \
main.c \
init_struct.c \
pipe_exec.c \
step_exec.c \
analyze_input.c \
analyze_output.c \
analyse_cmds.c \
path_tools.c \
here_doc.c \
error.c \
cleaning.c \
)
SRCS_BONUSOFF = $(addprefix $(SRC_DIR)/, \
bonus_off.c \
)
SRCS_BONUSON = $(addprefix $(SRC_DIR)/, \
bonus_on.c \
)

OBJS = $(SRCS:.c=.o)
OBJS_BONUSOFF = $(SRCS_BONUSOFF:.c=.o)
OBJS_BONUSON = $(SRCS_BONUSON:.c=.o)

all: lib $(NAME) $(NAME_BONUS)

$(NAME) : $(OBJS) $(OBJS_BONUSOFF) $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) $(OBJS_BONUSOFF) $(LIBFT_PATH) -o $(NAME) 

%.o: %.c $(HEADER_FILE)
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

bonus: lib $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS) $(OBJS_BONUSON) $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBJS) $(OBJS_BONUSON) $(LIBFT_PATH) -o $(NAME_BONUS) 

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(OBJS_BONUSOFF) $(OBJS_BONUSON) 

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

lib:
	make -C ./libft

.PHONY:	all bonus clean fclean re lib