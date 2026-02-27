#include "cub3d.h"

static int	count_map_lines(t_game *game, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (game->file[i])
	{
		count++;
		i++;
	}
	return (count);
}

static int	get_map_cols(t_game *game, int start)
{
	int	i;
	int	max;
	int	len;

	i = start;
	max = 0;
	while (game->file[i])
	{
		len = ft_strlen(game->file[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static void	copy_map(t_game *game, int	start)
{
	int	i;

	game->map.grid = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.grid)
		exit_error("Malloc map grid failed", game);
	i = 0;
	while (game->file[start])
	{
		game->map.grid[i] = ft_strdup(game->file[start]);
		if (!game->map.grid[i])
			exit_error("Malloc map copy failed", game);
		i++;
		start++;
	}
	game->map.grid[i] = NULL;
}

void	parse_map(t_game *game, int start)
{
	if (!game->file[start])
		exit_error("Map is empty", game);
	game->map.rows = count_map_lines(game, start);
	game->map.cols = get_map_cols(game, start);
	copy_map(game, start);
	validate_map(game);
}
