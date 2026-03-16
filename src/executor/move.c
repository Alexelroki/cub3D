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
	double	nx;
	double	ny;

	nx = game->player.pos_x + dx;
	ny = game->player.pos_y + dy;
	if (ft_can_move_to(game, nx, game->player.pos_y))
		game->player.pos_x = nx;
	if (ft_can_move_to(game, game->player.pos_x, ny))
		game->player.pos_y = ny;
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

void	ft_move_left(t_game *game)
{
	move_player(game, game->player.dir_y * MOVE_SPEED,
		-game->player.dir_x * MOVE_SPEED);
}

void	ft_move_right(t_game *game)
{
	move_player(game, -game->player.dir_y * MOVE_SPEED,
		game->player.dir_x * MOVE_SPEED);
}
