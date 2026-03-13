NAME = cub3D

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
INCLUDE	= -I inc -I $(LIBFT_DIR) -I $(MLX42_DIR)/include/MLX42

SRC_DIR	= src
OBJ_DIR	= obj
PARSE_DIR = $(SRC_DIR)/parser
EXEC_DIR = $(SRC_DIR)/executor
UTILS_DIR = $(SRC_DIR)/utils

SRC	=	$(SRC_DIR)/main.c \
		$(SRC_DIR)/init/init.c \
		$(SRC_DIR)/init/load_textures.c \
		$(SRC_DIR)/events/event.c \
		$(PARSE_DIR)/validate_args.c \
		$(PARSE_DIR)/parse_file.c \
		$(PARSE_DIR)/parse_header.c \
		$(PARSE_DIR)/parse_color.c \
		$(PARSE_DIR)/parse_map.c \
		$(PARSE_DIR)/validate_map.c \
		$(PARSE_DIR)/validate_map_floodfill.c \
		$(UTILS_DIR)/cleanup.c \
		$(UTILS_DIR)/error.c \
		$(EXEC_DIR)/draw.c \
		$(EXEC_DIR)/execute.c \
		$(EXEC_DIR)/input.c \
		$(EXEC_DIR)/move.c \
		$(EXEC_DIR)/raycasting.c \
		$(EXEC_DIR)/rotate.c \
		$(EXEC_DIR)/texture.c

OBJS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
# MLX42_DIR = /sgoinfre/shared/MLX42
MLX42_DIR = $(LIB_DIR)/MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42 = $(MLX42_BUILD)/libmlx42.a
MLX42FLAGS = -L$(MLX42_BUILD) -lmlx42 -ldl -lglfw -pthread -lm
DEPS	= $(OBJS:.o=.d)
RM = rm -f
SUPP = mlx42.supp

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX42):
	@cmake -B $(MLX42_BUILD) -S $(MLX42_DIR)
	@make -C $(MLX42_BUILD)

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(sort $(dir $(OBJS)))

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

val: all
	valgrind --leak-check=full --suppressions=$(SUPP) ./$(NAME) maps/valid/map_simple.cub

.PHONY: all clean fclean re val

-include $(DEPS)
