/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_floodfill.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/17 18:18:11 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**copy_map_grid(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(game->map.rows + 1, sizeof(char *));
	if (!map_copy)
		exit_error("Malloc map grid floodfill failed", game);
	i = 0;
	while (i < game->map.rows)
	{
		map_copy[i] = ft_strdup(game->map.grid[i]);
		if (!map_copy[i])
		{
			free_array(map_copy);
			exit_error("Malloc map copy line floodfill failed", game);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static int	flood_fill(t_game *game, char **map, int row, int col)
{
	if (row < 0 || row >= game->map.rows)
		return (0);
	if (col < 0 || col >= (int)ft_strlen(map[row]))
		return (0);
	if (map[row][col] == ' ')
		return (0);
	if (map[row][col] == '1' || map[row][col] == 'X')
		return (1);
	map[row][col] = 'X';
	if (!flood_fill(game, map, row - 1, col))
		return (0);
	if (!flood_fill(game, map, row + 1, col))
		return (0);
	if (!flood_fill(game, map, row, col - 1))
		return (0);
	if (!flood_fill(game, map, row, col + 1))
		return (0);
	return (1);
}

void	check_walls(t_game *game)
{
	char	**map_copy;
	int		start_row;
	int		start_col;
	int		result;

	map_copy = copy_map_grid(game);
	start_row = (int)game->player.pos_y;
	start_col = (int)game->player.pos_x;
	result = flood_fill(game, map_copy, start_row, start_col);
	free_array(map_copy);
	if (!result)
		exit_error("Map is not closed", game);
}
