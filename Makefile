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

# Archivos fuente para el proyecto completo
SRCS		:= src/main.c \
			   src/parser/parser.c \
			   src/executor/init.c

# Archivos solo para pruebas del executor
EXEC_SRCS	:= src/executor/init.c

OBJS		:= $(SRCS:.c=.o)
EXEC_OBJS	:= $(EXEC_SRCS:.c=.o)
DEPS		:= $(SRCS:.c=.d)

all: $(NAME)

# Target para compilar solo el executor (para pruebas)
executor: $(EXEC_TEST)

$(NAME): $(LIBFT_A) $(LIBMLX_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "✓ cub3D compiled"

$(EXEC_TEST): $(LIBFT_A) $(LIBMLX_A) $(EXEC_OBJS)
	@$(CC) $(CFLAGS) $(EXEC_OBJS) $(LIBS) -o $(EXEC_TEST)
	@echo "✓ test_executor compiled"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@

$(LIBFT_A):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR) -s

$(LIBMLX_A):
	@echo "Compiling MLX42..."
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build > /dev/null 2>&1 && cmake --build $(LIBMLX_DIR)/build -j4 > /dev/null 2>&1

clean:
	@rm -f $(OBJS) $(DEPS)
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