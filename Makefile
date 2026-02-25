NAME = cub3D

CC	= cc
CFLAGS	= -g #-Wall -Wextra -Werror -g
INCLUDE	= -I include -I libft -I $(MLX42_DIR)/include/MLX42

SRC_DIR	= src
OBJ_DIR	= obj

SRC	=	$(SRC_DIR)/main.c \
		$(SRC_DIR)/parser/validate_args.c \
		$(SRC_DIR)/parser/parse_file.c \
		$(SRC_DIR)/parser/parse_header.c \
		$(SRC_DIR)/parser/parse_color.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/events/event.c \
		$(SRC_DIR)/utils/cleanup.c \
		$(SRC_DIR)/utils/error.c

OBJS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
# MLX42_DIR = /sgoinfre/shared/MLX42
MLX42_DIR = MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42 = $(MLX42_BUILD)/libmlx42.a
MLX42FLAGS = -L$(MLX42_BUILD) -lmlx42 -ldl -lglfw -pthread -lm
DEPS	= $(OBJS:.o=.d)
RM = rm -f

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX42):
	@cmake -B $(MLX42_BUILD) -S $(MLX42_DIR)
	@make -C $(MLX42_BUILD)

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
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

.PHONY: all clean fclean re

-include $(DEPS)
