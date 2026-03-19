/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponce-g <dponce-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/19 13:46:15 by dponce-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_vector(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
}

void	ft_rotate_right(t_game *game)
{
	ft_rotate_by_angle(game, ROT_SPEED);
}

void	ft_rotate_left(t_game *game)
{
	ft_rotate_by_angle(game, -ROT_SPEED);
}

void	ft_rotate_by_angle(t_game *game, double angle)
{
	rotate_vector(&game->player.dir_x, &game->player.dir_y, angle);
	rotate_vector(&game->player.plane_x, &game->player.plane_y, angle);
}
