#include "cub3d.h"

static char	*g_test_map[] = {
	"111111111111111111111111",
	"100000000000000000000001",
	"101100000111000000000001",
	"100100000000000000000001",
	"111111111011000001100001",
	"100000000011000001100001",
	"100000000000000000000001",
	"100000000000000000000001",
	"100000000000000000000001",
	"100000000000000000000001",
	"100000000000000000000001",
	"100000000000000000000001",
	"111111111111111111111111",
	NULL
};

/* static char	*g_test_map[] = {
	"111111111111111111111111111111111",
	"111111111000000000110000000000001",
	"111111111011000001110000000000001",
	"111111111001000000000000000000001",
	"111111111011000001110000000000001",
	"100000000011000001110111111111111",
	"111101111111110111000000100011111",
	"111101111111110111010100100011111",
	"110000001101010111000000100011111",
	"100000000000000011000000100011111",
	"100000000000000011010100100011111",
	"11000001110101011111011110N011111",
	"111101111111010111011110100011111",
	"111111111111111111111111111111111",
	NULL
}; */

/* static void	init_map(t_game *game)
{
	int	i;

	game->map.grid = g_test_map;
	game->map.height = 0;
	i = 0;
	while (g_test_map[i])
	{, 
		game->map.height++;
		i++;
	}
	game->map.width = ft_strlen(g_test_map[0]);
} */

static void	init_map(t_game *game)
{
	int	i;

	game->map.grid = g_test_map;
	game->map.height = 0;
	i = 0;
	while (g_test_map[i])
	{
		game->map.height++;
		i++;
	}
	game->map.width = 24;
}

static void	init_player(t_game *game)
{//falta poner la posicion del jugador en el mapa y su direccion inicial segun el mapa
	game->player.pos_x = 12.5;
	game->player.pos_y = 6.5;
	/*if (game->map.grid[6][12] == 'N')
	{*/
	game->player.dir_x = 0.0;
	game->player.dir_y = -0.5;
	game->player.plane_x = 0.8;//0.66;
	game->player.plane_y = 0.0;
	/*}
	else if (game->map.grid[6][12] == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->map.grid[6][12] == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
	else if (game->map.grid[6][12] == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	} */
}

static void	init_textures(t_game *game)
{
	game->tex.north = mlx_load_png("./textures/NO.png");
	game->tex.south = mlx_load_png("./textures/SO.png");
	game->tex.west = mlx_load_png("./textures/WEST.png");
	game->tex.east = mlx_load_png("./textures/EA.png");
}

void	init_game(t_game *game)
{
	init_map(game);
	init_player(game);
	init_textures(game);
	game->floor_color = 0x0E484FFF;
	game->ceiling_color = 0x4F150EFF;
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!game.mlx)
		return (1);
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (!game.img)
		return (mlx_terminate(game.mlx), 1);
	if (mlx_image_to_window(game.mlx, game.img, 0, 0) == -1)
		return (mlx_terminate(game.mlx), 1);
	init_game(&game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop_hook(game.mlx, handle_input, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}