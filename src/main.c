#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		map_start;

	validate_args(argc, argv);
	init_game(&game);
	parse_file(&game, argv[1]);
	map_start = parse_header(&game);
	parse_map(&game, map_start);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
