#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		map_start;

	init_game(&game);
	validate_args(argc, argv);
	parse_file(&game, argv[1]);
	map_start = parse_header(&game);
	parse_map(&game, map_start);
	init_player_dir(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
