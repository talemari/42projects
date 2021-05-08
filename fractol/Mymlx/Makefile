# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talemari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 15:17:33 by talemari          #+#    #+#              #
#    Updated: 2017/01/06 18:08:44 by talemari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mymlx.a

SRC_DIR = src/
OBJ_DIR = obj/
LIB_MLX = libmlx.a
LIB_FT = Libft/libft.a

EXT_C = .c
EXT_HEAD = .h
SRC =	mm_3d_to_ortho			\
		mm_color_to_hex			\
		mm_dotcpy				\
		mm_hex_to_color			\
		mm_line					\
		mm_mat_4x4_to_3x3		\
		mm_mat_mult3x3			\
		mm_mat_mult4x4			\
		mm_mat_ortho_projection	\
		mm_mat_rotation_x		\
		mm_mat_rotation_y		\
		mm_mat_rotation_z		\
		mm_mat_scale			\
		mm_mat_translation		\
		mm_mat1x3f				\
		mm_mat4x4_mult_vec3f	\
		mm_pixel_put_img		\
		mm_pixel_put			\
		mm_triangle				\
		mm_vec2f				\
		mm_vec2fcmp				\
		mm_vec3f				\
		mm_vec3i				\
		mm_vec_multi_mat		\
		vector2i	

SRC_SRC = $(addsuffix $(EXT_C), $(SRC))
OBJ_SRC = $(addprefix $(OBJ_DIR), $(SRC_SRC:.c=.o))
HEADERS = $(addsuffix $(EXT_HEAD), $(SRC))
LOCAL_HEADERS = $(addprefix $(INC_DIR), $(HEADERS))
DEP_SRC := $(OBJ_SRC:.o=.d)

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
CXX = gcc
FLAGS = -Wall -Wextra -Werror
DFLAGS = -MMD -MP
IFLAGS = -I./inc -I./Mymlx -I../minilibx-linux -I./ -I./Libft/inc
OFLAGS = -c -o
LINKER =
DEBUGFLAG = -g

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@ar rcs $(NAME) $(OBJ_SRC)
	@ranlib $(NAME)
	@$(ECHO) "$(C_MAGENTA)$(NAME) compilation done.$(C_NONE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CXX) $(FLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@
	@$(ECHO) "$(C_MAGENTA)$@ compilation done.$(C_NONE)"

clean:
	@/bin/rm -Rf $(OBJ_DIR)
	@$(ECHO) "$(C_GREEN)$(NAME) clean done.$(C_NONE)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -Rf $(LIB_DIR)
	@$(ECHO) "$(C_GREEN)$(NAME) fclean done.$(C_NONE)"

install : $(NAME)
	@cp $(LOCAL_HEADERS) $(TARGET_INC_DIR)
	@cp $(NAME) $(TARGET_LIB_DIR)
	@$(ECHO) "$(C_MAGENTA)$(HEADERS) copied.$(C_NONE)"
	@$(ECHO) "$(C_MAGENTA)$(NAME) installed.$(C_NONE)"

uninstall :
	@rm $(TARGET_HEADER)
	@rm $(TARGET_LIB)
	@$(ECHO) "$(C_BLUE)$(HEADERS) removed.$(C_NONE)"
	@$(ECHO) "$(C_BLUE)$(NAME) uninstalled.$(C_NONE)"

re: fclean all
	
PHONY : re all clean fclean
	@$(ECHO) "$(C_GREEN)$(NAME) .PHONY done.$(C_NONE)"

.PHONY: all clean fclean re

-include $(DEP_SRC)
-include $(DEP_SRC_C)