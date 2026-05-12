# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 14:20:42 by .frnki            #+#    #+#              #
#    Updated: 2026/04/21 16:20:42 by .frnki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME		= push_swap.a

# COMPILER
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

#SRC- & OBJ-FILES
SOURCE_FILES 	=	checks.c

OBJECT_FILES = ${SOURCE_FILES:.c=.o}

# LIBFT
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# ARCHIVE MERGING
all: $(NAME)

$(NAME): $(OBJECT_FILES) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJECT_FILES)
	@echo "#    PUSH_SWAP COMPILED VaL & .frnki  #"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJECT_FILES)
	@make clean -sC $(LIBFT_DIR)
	@echo "#     PUSH_SWAP CLEANED VaL & .frnki  #"
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
re: fclean all
.PHONY: all clean fclean re
