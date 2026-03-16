/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/10 00:00:00 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*pad_line(t_game *game, char *line)
{
	char	*padded;
	int		len;
	int		i;

	len = ft_strlen(line);
	padded = malloc(sizeof(char) * (game->map.cols + 1));
	if (!padded)
		exit_error("Malloc map line failed", game);
	i = 0;
	while (i < len)
	{
		padded[i] = line[i];
		i++;
	}
	while (i < game->map.cols)
	{
		padded[i] = ' ';
		i++;
	}
	padded[i] = '\0';
	return (padded);
}

static void	copy_map(t_game *game, int start)
{
	int	i;

	game->map.grid = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.grid)
		exit_error("Malloc map grid failed", game);
	i = 0;
	while (game->file[start])
	{
		game->map.grid[i] = pad_line(game, game->file[start]);
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
