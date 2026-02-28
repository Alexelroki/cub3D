# Nombre del archivo de la biblioteca
NAME = libft.a

# Compilador y banderas de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Crear bibliotecas y eliminar archivos
AR = ar rcs
RM = rm -f

# Archivos fuente y archivos objeto
SRC = ft_atoi.c\
      ft_isdigit.c\
      ft_memmove.c\
      ft_strlen.c\
      ft_toupper.c\
      ft_bzero.c\
      ft_isprint.c\
      ft_memset.c\
      ft_strncmp.c\
      ft_isalnum.c\
      ft_memchr.c\
      ft_strchr.c\
      ft_strnstr.c\
      ft_isalpha.c\
      ft_memcmp.c\
      ft_strlcat.c\
      ft_strrchr.c\
      ft_isascii.c\
      ft_memcpy.c\
      ft_strlcpy.c\
      ft_tolower.c\
      ft_calloc.c\
      ft_strdup.c\
      ft_substr.c\
      ft_strjoin.c\
      ft_strtrim.c\
      ft_split.c\
      ft_itoa.c\
      ft_strmapi.c\
      ft_striteri.c\
      ft_putchar_fd.c\
      ft_putstr_fd.c\
      ft_putendl_fd.c\
      ft_putnbr_fd.c\
      ft_lstnew_bonus.c\
      ft_lstadd_front_bonus.c\
      ft_lstsize_bonus.c\
      ft_lstlast_bonus.c\
      ft_lstadd_back_bonus.c\
      ft_lstdelone_bonus.c\
      ft_lstclear_bonus.c\
      ft_lstiter_bonus.c\
      ft_lstmap_bonus.c\
      get_next_line.c\
      ft_printf.c\
      ft_put.c\
      ft_converter.c
OBJ = $(SRC:.c=.o)

# Archivos de encabezado
INCLUDE = libft.h

# Indica que las siguientes reglas no son archivos
.PHONY: all clean fclean re

# Regla por defecto que lo compila todo
all: $(NAME)

# Regla para crear la biblioteca
$(NAME): $(OBJ)
	$(AR) $@ $^

# Pasar archivos .c a .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

# Regla para eliminar todos los archivos objeto creados
clean:
	$(RM) $(OBJ)

# Eliminar todos los archivos .o y .a
fclean: clean
	$(RM) $(NAME)
re: fclean all
