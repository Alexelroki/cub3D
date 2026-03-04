#include "cub3d.h"

/*static char	*grid[] =
{
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
};*/

void	draw_square(t_game *game, int row, int col, int color)
{
	int	i;
	int	j;
	int	tile_width;
	int	tile_height;
	int	offset_x;
	int	offset_y;

	tile_width = WIDTH / game->map.cols;
	tile_height = HEIGHT / game->map.rows;
	offset_x = (WIDTH - (tile_width * game->map.cols)) / 2;
	offset_y = (HEIGHT - (tile_height * game->map.rows)) / 2;
	i = 0;
	while (i < tile_height)
	{
		j = 0;
		while (j < tile_width)
		{
			mlx_put_pixel(game->img, (col * tile_width) + j + offset_x, (row * tile_height) + i + offset_y, color);
			j++;
		}
		i++;
	}
}

/*// Print the window width and height.
static void	ft_hook(t_game* game)
{
        printf("WIDTH: %d | HEIGHT: %d\n", game->mlx->width, game->mlx->height);
}*/

int	start_game(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	/*(void)grid;
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game.mlx, game.img, 0, 0);
	draw_square(&game);
	//mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);*/
	return (0);
}
