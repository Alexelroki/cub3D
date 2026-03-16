/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/16 00:00:00 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MOUSE_SENS 0.003

static void	handle_mouse(t_game *game)
{
	static int	mouse_ready;
	int32_t		mx;
	int32_t		my;
	int			delta_x;

	mlx_get_mouse_pos(game->mlx, &mx, &my);
	if (!mouse_ready)
	{
		mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
		mouse_ready = 1;
		return ;
	}
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
