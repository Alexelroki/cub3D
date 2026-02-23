NAME = cub3D

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -I include -I libft -I ../MLX42/include

SRC_DIR	= src
OBJ_DIR	= obj

SRCS	=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/utils/error.c

OBJS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX42_DIR = ../MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42 = $(MLX42_BUILD)/libmlx42.a
MLX42FLAGS = -L$(MLX42_BUILD) -lmlx42 -ldl -lglfw -pthread -lm
DEPS	= $(OBJS:.o=.d)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
