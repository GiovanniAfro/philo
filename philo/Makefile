# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 15:11:53 by gcavanna          #+#    #+#              #
#    Updated: 2023/07/10 15:22:26 by gcavanna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c utils.c init.c routine.c state.c 

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra
LINKS = -lpthread

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all

RED		:= ${shell tput setaf 1}
ITALIC	:= ${shell tput sitm}

banner:

${info ${RED}}
${info • ▄▄ •           ▄▄▄ . ▄▄▄· ▄▄▄▄▄     ▄· ▄▌      ▄• ▄▌▄▄▄      .▄▄ ·  ▄▄▄· ▄▄▄·  ▄▄ •  ▄ .▄▄▄▄ .▄▄▄▄▄▄▄▄▄▄▪       ▄· ▄▌      ▄• ▄▌     ▄▄▄·▄• ▄▌ ▐ ▄ ▄ •▄}
${info ▐█ ▀ ▪▪         ▀▄.▀·▐█ ▀█ •██      ▐█▪██▌▪     █▪██▌▀▄ █·    ▐█ ▀. ▐█ ▄█▐█ ▀█ ▐█ ▀ ▪██▪▐█▀▄.▀·•██  •██  ██     ▐█▪██▌▪     █▪██▌    ▐█ ▄██▪██▌•█▌▐██▌▄▌▪ }
${info ▄█ ▀█▄ ▄█▀▄     ▐▀▀▪▄▄█▀▀█  ▐█.▪    ▐█▌▐█▪ ▄█▀▄ █▌▐█▌▐▀▀▄     ▄▀▀▀█▄ ██▀·▄█▀▀█ ▄█ ▀█▄██▀▐█▐▀▀▪▄ ▐█.▪ ▐█.▪▐█·    ▐█▌▐█▪ ▄█▀▄ █▌▐█▌     ██▀·█▌▐█▌▐█▐▐▌▐▀▀▄· }
${info ▐█▄▪▐█▐█▌.▐▌    ▐█▄▄▌▐█ ▪▐▌ ▐█▌·     ▐█▀·.▐█▌.▐▌▐█▄█▌▐█•█▌    ▐█▄▪▐█▐█▪·•▐█ ▪▐▌▐█▄▪▐███▌▐▀▐█▄▄▌ ▐█▌· ▐█▌·▐█▌     ▐█▀·.▐█▌.▐▌▐█▄█▌    ▐█▪·•▐█▄█▌██▐█▌▐█.█▌ }
${info ·▀▀▀▀  ▀█▄▀▪     ▀▀▀  ▀  ▀  ▀▀▀       ▀ •  ▀█▄▀▪ ▀▀▀ .▀  ▀     ▀▀▀▀ .▀    ▀  ▀ ·▀▀▀▀ ▀▀▀ · ▀▀▀  ▀▀▀  ▀▀▀ ▀▀▀      ▀ •  ▀█▄▀▪ ▀▀▀     .▀    ▀▀▀ ▀▀ █▪·▀  ▀ }
${info ${BOLD}${ITALIC}${YELLOW}                        			eat, sleep, code, repeat}
${info ${RED}}
# ------------------------------------------------------------------------------
