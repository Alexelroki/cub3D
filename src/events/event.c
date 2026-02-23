#include "cub3d.h"

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
}
