NAME = fractol

SRC_DIR = src/
INC_DIR = inc/
OBJ_DIR = obj/
LIB_MLX = minilibx-linux/libmlx_Linux.a
LIB_MYMLX = Mymlx/mymlx.a
LIB_FT = Mymlx/Libft/libft.a

EXT_C = .c
EXT_HEAD = .h
SRC = 			fractol\
				mandelbrot\
				set_data\
				key_is_pressed\
				trigger_zoom\
				julia\
				tricorn\
				mouse_is_pressed\
				mouse_motion

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
FLAGS = -Wall -Wextra -Werror -g
DFLAGS = -MMD -MP
IFLAGS = -I./inc -I./Mymlx/inc -I./minilibx-linux -I./ -I./Mymlx/Libft/inc
LINKERFLAGS = -L./minilibx-linux -lm -lX11 -lXext -lX11 -lmlx
OFLAGS = -c -o
LINKER =
DEBUGFLAG = -g

all: $(NAME)

$(NAME): $(OBJ_SRC) $(LIB_MLX) $(LIB_MYMLX) $(LIB_FT)
	@$(CXX) $(FLAGS) $(IFLAGS) $(OBJ_SRC) $(LIB_MLX) $(LIB_MYMLX) $(LINKERFLAGS) $(LIB_FT) -o $(NAME)
	@$(ECHO) "$(C_MAGENTA)$(NAME) compilation done.$(C_NONE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@/bin/mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@
	@$(ECHO) "$(C_MAGENTA)$@ compilation done.$(C_NONE)"

$(LIB_MLX) :
	@cd minilibx-linux && ./configure

$(LIB_MYMLX) :
	@cd Mymlx && make

$(LIB_FT) :
	@cd Mymlx/Libft && make

clean:
	@/bin/rm -Rf $(OBJ_DIR)
	@$(ECHO) "$(C_GREEN)$(NAME) clean done.$(C_NONE)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -Rf $(LIB_DIR)
	@$(ECHO) "$(C_GREEN)$(NAME) fclean done.$(C_NONE)"

fcleanlibs : fclean
	@cd Mymlx && make fclean;
	@cd Mymlx/Libft && make fclean
	@cd minilibx-linux && make clean

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