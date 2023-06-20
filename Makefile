# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 15:11:53 by gcavanna          #+#    #+#              #
#    Updated: 2023/06/20 14:15:43 by gcavanna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors constants
PURPLE			= \033[38;5;141m
GREEN			= \033[38;5;46m
RED				= \033[0;31m
GREY			= \033[38;5;240m
RESET			= \033[0m
BOLD			= \033[1m
CLEAR			= \r\033[K

# Executable and compilation
NAME		= philo

SRC_DIR		= ./srcs/
SRCS		= philo.c \
		  utils.c \

OBJ_DIR		= ./objs/
OBJS    	= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -rf

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@printf "\033[2K\r» [$(NAME)]: Compiling %s... " $(notdir $<)
	@$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\033[2K\r────────────────────────────────────────────────────────────────────────────\n» [$(NAME)]: $(NAME) compiled successfully.\n────────────────────────────────────────────────────────────────────────────\n"

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(MAKE) clean -C $(SRC_DIR)
	@$(RM) $(OBJ_DIR)
	@printf "\033[2K\r» [$(NAME)]: Objects were cleaned successfully.\n"

fclean: clean
	@$(MAKE) fclean -C $(SRC_DIR)
	@$(RM) $(NAME)
	@printf "\033[2K\r────────────────────────────────────────────────────────────────────────────\n» [$(NAME)]: Project cleaned successfully.\n────────────────────────────────────────────────────────────────────────────\n"

re: fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re
