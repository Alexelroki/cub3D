#include "cub3d.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, TITLE, false);
	if (!game->mlx)
		exit_error("Error init MLX42", game);
}

static void	set_player_dir(t_game *game)
{
	if (game->player.spawn_dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->player.spawn_dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->player.spawn_dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (game->player.spawn_dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
}

static void	set_player_plane(t_game *game)
{
	if (game->player.spawn_dir == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->player.spawn_dir == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (game->player.spawn_dir == 'W')
	{
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	else if (game->player.spawn_dir == 'E')
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
}

void	init_player_dir(t_game *game)
{
	set_player_dir(game);
	set_player_plane(game);
}

void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->textures.floor_color = -1;
	game->textures.ceil_color = -1;
	game->player.pos_x = -1;
	game->player.pos_y = -1;
}
