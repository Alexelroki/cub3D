#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	validate_args(argc, argv);
	init_game(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
