/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/10 00:00:00 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player(t_game *game, double dx, double dy)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + dx;
	new_y = game->player.pos_y + dy;
	if (new_x >= 0 && new_x < game->map.cols
		&& game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	if (new_y >= 0 && new_y < game->map.rows
		&& game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
}

void	ft_move_forward(t_game *game)
{
	move_player(game, game->player.dir_x * MOVE_SPEED,
		game->player.dir_y * MOVE_SPEED);
}

void	ft_move_backward(t_game *game)
{
	move_player(game, -game->player.dir_x * MOVE_SPEED,
		-game->player.dir_y * MOVE_SPEED);
}
