#include "cub3d.h"

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ')
		return (1);
	return (0);
}

static void	check_chars(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map.grid[row])
	{
		col = 0;
		while (game->map.grid[row][col])
		{
			if (!is_valid_char(game->map.grid[row][col]))
				exit_error("Invalid character in map", game);
			col++;
		}
		row++;
	}
}

static void	find_player(t_game *game)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (game->map.grid[row])
	{
		col = 0;
		while (game->map.grid[row][col])
		{
			c = game->map.grid[row][col];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				if (game->player.pos_x != -1)
					exit_error("Multiple spawns found", game);
				game->player.pos_x = col + 0.5;
				game->player.pos_y = row + 0.5;
				game->player.spawn_dir = c;
			}
			col++;
		}
		row++;
	}
	if (game->player.pos_x == -1)
		exit_error("No spawn found", game);
}

void	validate_map(t_game *game)
{
	check_chars(game);
	find_player(game);
	check_walls(game);
}
