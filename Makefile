# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:48:28 by nmuller           #+#    #+#              #
#    Updated: 2016/11/25 02:53:04 by nicolas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############
# PARAMETERS #
##############

# directories
SRC_PATH = src
OBJ_PATH = obj
CPPFLAGS = -Iinclude

# libraries
LDFLAGS = -Llibft
LDLIBS = -lft

# compiler flags
CC = clang
CFLAGS = -Werror -Wall -Wextra

# files
SRC_FILES =	arg_handler.c \
			conv_misc.c \
			display.c \
			ft_printf.c \
			parsing.c \
			conv_number.c \
			ft_itoa_base_spec.c \
			utils.c \
			main.c

# executable name
NAME = libftprintf.a

##############
# PROCESSING #
##############

# variables creation
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

# rules
.PHONY: clean, fclean, re, norme
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
