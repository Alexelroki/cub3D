#include "cub3d.h"

static void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, TITLE, false);
	if (!game->mlx)
		exit_error("Error init MLX42", game);
}

static void	init_image(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		exit_error("mlx_new_image failed\n", game);
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0)
		exit_error("mlx_image_to_window failed\n", game);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_image(game);
}
