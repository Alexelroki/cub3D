/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/10 00:00:00 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_vector(double *x, double *y, double angle)
{ // Queremos saber el nuevo valor de cos()/vector x y sin()/vector tra
/*
** Rota un vector 2D por un ángulo en radianes.
** Se usa para rotar tanto la dirección del jugador (dir)
** como el plano de cámara (plane).
*/
	double	old_x;

	old_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
}

void	ft_rotate_right(t_game *game)
{
	/*
	** Rotamos dir y plane con el mismo ángulo:
	** así mantienen su relación y el FOV no se deforma.
	*/
	rotate_vector(&game->player.dir_x, &game->player.dir_y, ROT_SPEED);
	rotate_vector(&game->player.plane_x, &game->player.plane_y, ROT_SPEED);
}

void	ft_rotate_left(t_game *game)
{
	/* Mismo proceso, pero en sentido contrario. */
	rotate_vector(&game->player.dir_x, &game->player.dir_y, -ROT_SPEED);
	rotate_vector(&game->player.plane_x, &game->player.plane_y, -ROT_SPEED);
}
