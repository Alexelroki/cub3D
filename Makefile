NAME	:= cub3D

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iinc

SRC_DIR	:= src
OBJ_DIR	:= obj

SRCS	:= $(SRC_DIR)/actions.c \
		   $(SRC_DIR)/extreme_cases.c \
		   $(SRC_DIR)/extreme_eat.c \
		   $(SRC_DIR)/init.c \
		   $(SRC_DIR)/main.c \
		   $(SRC_DIR)/monitor.c \
		   $(SRC_DIR)/parse.c \
		   $(SRC_DIR)/simulation.c \
		   $(SRC_DIR)/utils.c

OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

DEPS	:= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
