/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/16 00:00:00 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_blocked(t_game *game, double x, double y)
{
	char	cell;

	if (x < 0 || y < 0 || x >= game->map.cols || y >= game->map.rows)
		return (1);
	cell = game->map.grid[(int)y][(int)x];
	if (cell == '1' || cell == ' ')
		return (1);
	return (0);
}

int	ft_can_move_to(t_game *game, double x, double y)
{
	double	r;

	r = PLAYER_RADIUS;
	if (is_blocked(game, x - r, y - r))
		return (0);
	if (is_blocked(game, x + r, y - r))
		return (0);
	if (is_blocked(game, x - r, y + r))
		return (0);
	if (is_blocked(game, x + r, y + r))
		return (0);
	return (1);
}
