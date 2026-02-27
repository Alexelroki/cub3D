#include "cub3d.h"

static char	**copy_map_grid(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!map_copy)
		exit_error("Malloc map grid floodfill failed", game);
	i = 0;
	while (i < game->map.rows)
	{
		map_copy[i] = ft_strdup(game->map.grid[i]);
		if (!map_copy[i])
			exit_error("Malloc map copy line floodfill failed", game);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	flood_fill(t_game *game, char **map, int row, int col)
{
	if (row < 0 || row >= game->map.rows)
		exit_error("Map is not closed", game);
	if (col < 0 || col >= (int)ft_strlen(map[row])) //Tenemos filas con diferentes tamaños
		exit_error("Map is not closed", game);
	if (map[row][col] == ' ')
		exit_error("Map is not closed", game);
	if (map[row][col] == 1 || map[row][col] == 'X')
		return ;
	map[row][col] == 'X';
	flood_fill(game, map, row - 1, col);
	flood_fill(game, map, row + 1, col);
	flood_fill(game, map, row, col - 1);
	flood_fill(game, map, row, col + 1);
}

void	check_walls(t_game *game)
{
	char	**map_copy;
	int		start_row;
	int		start_col;

	map_copy = copy_map_grid(game);
	start_row = (int)game->player.pos_y;
	start_col = (int)game->player.pos_x;
	flood_fill(game, map_copy, start_row, start_col);
	free_array(map_copy);
}
