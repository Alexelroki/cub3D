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

typedef struct s_textures
{
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	int				floor_color;
	int				cecil_color;
}	t_textures;

typedef struct s_map
{
	
}	t_map;

typedef struct s_player
{
	
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**file;
	t_textures	*textures;
	t_map		*map;
	t_player	*player;
}	t_game;

void	validate_args(int argc, char **argv);
void	parse_file(t_game *game, char *file);
void	init_game(t_game *game);

void	setup_hooks(t_game *game);

void	cleanup_game(t_game *game);
void	exit_error(const char *message, t_game *game);

#endif