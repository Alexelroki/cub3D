#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "MLX42.h"

# define TITLE "cub3D"
# define WIDTH	800
# define HEIGHT	600

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_game;

void	init_game(t_game *game);

void	setup_hooks(game);

void	cleanup_game(t_game *game);
void	exit_error(const char *message, t_game *game);

#endif