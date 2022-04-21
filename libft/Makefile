# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 11:45:53 by f██████           #+#    #+#              #
#    Updated: 2022/03/29 16:06:49 by f██████          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OBJS_CHAR = $(SRC_CHAR:.c=.o)
SRC_CHAR	= $(addprefix $(SRC_DIR)/char/, \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_tolower.c \
ft_toupper.c \
)
OBJS_LST = $(SRC_LST:.c=.o)
SRC_LST	= $(addprefix $(SRC_DIR)/lst/, \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstfirst.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \
)
OBJS_MEM = $(SRC_MEM:.c=.o)
SRC_MEM	= $(addprefix $(SRC_DIR)/mem/, \
ft_bzero.c \
ft_calloc.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_free_m.c \
ft_malloc_d.c \
)
OBJS_CONV = $(SRC_CONV:.c=.o)
SRC_CONV = $(addprefix $(SRC_DIR)/conv/, \
ft_atoi.c \
ft_itoa.c \
)
OBJS_STR = $(SRC_STR:.c=.o)
SRC_STR	= $(addprefix $(SRC_DIR)/str/, \
ft_split.c \
ft_strchr_i.c \
ft_strchr.c \
ft_strdup.c \
ft_strndup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strnjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
)
OBJS_PUT = $(SRC_PUT:.c=.o)
SRC_PUT	= $(addprefix $(SRC_DIR)/put/, \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_putunbr_fd.c \
)
OBJS_ARR = $(SRC_ARR:.c=.o)
SRC_ARR	= $(addprefix $(SRC_DIR)/arr/, \
ft_arrlen_pnt.c \
ft_arrfree_pnt.c \
)
OBJS_PRINTF = $(SRC_PRINTF:.c=.o)
SRC_PRINTF	= $(addprefix $(SRC_DIR)/printf/, \
ft_printf.c \
i_to_hex.c \
putc_fd.c \
putdi_fd.c \
putp_fd.c \
puts_fd.c \
putu_fd.c \
putx1_fd.c \
putx2_fd.c \
ull_to_hex.c \
)
OBJS_GNL = $(SRC_GNL:.c=.o)
SRC_GNL	= $(addprefix $(SRC_DIR)/gnl/, \
get_next_line.c \
)

SRC_DIR	= .
INC_DIR	= ./includes/
OUT	= libft.a
CC = gcc
AR = ar
FLAGS = -Wall -Wextra -Werror
HEADER_FILE	= $(INC_DIR)/libft.h

all: $(OUT)

$(NAME) : $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL) $(AR) $(NAME) $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL) ranlib $(NAME)

$(OUT) : $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL)
	$(AR) -rcs $(OUT) $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL)

%.o: %.c $(HEADER_FILE)
	$(CC) $(FLAGS) -c $< -o $@  -I $(INC_DIR) 

clean:
	rm -f $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_ARR) $(OBJS_PRINTF) $(OBJS_GNL)

fclean : clean
	rm -f $(OUT)

re : fclean all

.PHONY: all clean fclean re