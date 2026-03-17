/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/17 17:01:31 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MOUSE_SENS 0.003

static void	set_mouse_capture(t_game *game, int enabled)
{
	game->mouse_captured = enabled;
	if (enabled)
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
		mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	}
	else
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
}

static void	handle_mouse(t_game *game)
{
	int32_t		mx;
	int32_t		my;
	int			delta_x;

	if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT)
		&& !game->mouse_captured)
		set_mouse_capture(game, 1);
	else if (!mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT)
		&& game->mouse_captured)
		set_mouse_capture(game, 0);
	if (!game->mouse_captured)
		return ;
	mlx_get_mouse_pos(game->mlx, &mx, &my);
	delta_x = mx - (WIDTH / 2);
	if (delta_x != 0)
		ft_rotate_by_angle(game, delta_x * MOUSE_SENS);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
}

void	handle_input(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		ft_move_forward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		ft_move_backward(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		ft_move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		ft_move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_rotate_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_rotate_right(game);
	handle_mouse(game);
}
