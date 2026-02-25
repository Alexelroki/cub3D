NAME		:= cub3D
EXEC_TEST	:= test_executor

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
LIBFT_DIR	:= inc/libft
LIBMLX_DIR	:= inc/MLX42
INCLUDE		:= -Iinc -I$(LIBMLX_DIR)/include -I$(LIBFT_DIR)
LIBFT_A		:= $(LIBFT_DIR)/libft.a
LIBMLX_A	:= $(LIBMLX_DIR)/build/libmlx42.a
LIBS		:= $(LIBFT_A) $(LIBMLX_A) -ldl -lglfw -lpthread -lm
SRC_DIR	:= src
OBJ_DIR	:= obj
DEP_DIR	:= deps

# Archivos fuente para el proyecto completo
SRCS		:= $(SRC_DIR)/main.c \
		   $(SRC_DIR)/parser/parser.c \
		   $(SRC_DIR)/executor/init.c \
		   $(SRC_DIR)/executor/raycasting.c \
		   $(SRC_DIR)/executor/draw.c \
		   $(SRC_DIR)/executor/input.c

# Archivos solo para pruebas del executor
EXEC_SRCS	:= $(SRC_DIR)/executor/init.c \
		   $(SRC_DIR)/executor/raycasting.c \
		   $(SRC_DIR)/executor/draw.c \
		   $(SRC_DIR)/executor/input.c

OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
EXEC_OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(EXEC_SRCS))
DEPS		:= $(patsubst $(SRC_DIR)/%.c,$(DEP_DIR)/%.d,$(SRCS))

all: $(NAME)

# Target para compilar solo el executor (para pruebas)
executor: $(EXEC_TEST)

$(NAME): $(LIBFT_A) $(LIBMLX_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "✓ cub3D compiled"

$(EXEC_TEST): $(LIBFT_A) $(LIBMLX_A) $(EXEC_OBJS)
	@$(CC) $(CFLAGS) $(EXEC_OBJS) $(LIBS) -o $(EXEC_TEST)
	@echo "✓ test_executor compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) $(dir $(DEP_DIR)/$*)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

$(LIBFT_A):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR) -s

$(LIBMLX_A):
	@echo "Compiling MLX42..."
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && cmake --build $(LIBMLX_DIR)/build -j4

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@echo "✓ Cleaned"

fclean: clean
	@rm -f $(NAME) $(EXEC_TEST)
	@rm -rf $(LIBMLX_DIR)/build
	@make -C $(LIBFT_DIR) fclean -s
	@echo "✓ Full clean"

re: fclean all

.PHONY: all executor clean fclean re

-include $(DEPS)