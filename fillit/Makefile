# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talemari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:08:51 by talemari          #+#    #+#              #
#    Updated: 2017/12/15 16:00:16 by grota            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = src/
INC_PATH = inc/
LIB_PATH = Libft/
LIB_NAME = Libft/libft.a

SRC = main \
	  read \
	  check \
	  printgrid \
	  convert \
	  solver \
	  fill_grid \
	  ft_bitx_isone \
	  ft_error_exit

OBJ_DIR = obj

EXT_C = .c

SRC_SRC = $(addsuffix $(EXT_C), $(SRC))
SRC_2 = $(addprefix $(SRC_PATH), $(SRC_SRC))

FLG = -Wall -Werror -Wextra
IFLAGS = -I./inc -I./Libft/inc -lm

C_NONE = \033[0m
C_BOLD = \033[1m
C_BLACK = \033[30m
C_RED = \033[31m
C_GREEN = \033[32m
C_BROWN = \033[33m
C_BLUE = \033[34m
C_MAGENTA = \033[35m
C_CYAN = \033[36m
C_GRAY = \033[37m

ECHO = echo

all: $(NAME)

$(NAME): $(LIB_NAME)
	@gcc $(FLG) $(IFLAGS) $(SRC_2) $(LIB_NAME) -o $(NAME)
	@$(ECHO) "$(C_GREEN)$(NAME) compilation done.$(C_NONE)"

$(LIB_NAME) :
	@cd $(LIB_PATH) && make

$(OBJ_DIR)/%.o : ./src/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@gcc $(FLG)  -I./inc -o $@ $<

clean:
	@/bin/rm -Rf $(OBJ_DIR)
	@make -C $(LIB_PATH) clean
	@$(ECHO) "$(C_GREEN)$(NAME) clean done.$(C_NONE)"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@$(ECHO) "$(C_GREEN)$(NAME) fclean done.$(C_NONE)"

re: fclean all

PHONY : re all clean fclean
	@$(ECHO) "$(C_GREEN)$(NAME) .PHONY done.$(C_NONE)"

.PHONY: all clean fclean re
