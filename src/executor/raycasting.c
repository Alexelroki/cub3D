/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/10 00:00:00 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Inicializa los datos del rayo para una columna de pantalla.
** x: columna actual [0..WIDTH-1]
** camera_x: posición de esa columna en el plano de cámara [-1..1].
*/
void	init_ray_data(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	ray->raydir_x = game->player.dir_x + game->player.plane_x * camera_x;
	ray->raydir_y = game->player.dir_y + game->player.plane_y * camera_x;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	if (ray->raydir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		/* Distancia del rayo entre dos cruces verticales consecutivos. */
		ray->delta_dist_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		/* Distancia del rayo entre dos cruces horizontales consecutivos. */
		ray->delta_dist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}

void	calculate_step_data(t_ray *ray, t_player *player)
{
	/* step_x/step_y indican si avanzamos celda a celda en +1 o -1. */
	/* side_dist_x/side_dist_y: distancia inicial hasta el siguiente lado de celda. */
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		/* Si vamos en +X, el siguiente borde vertical está en map_x + 1. */
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		/* Si vamos en +Y, el siguiente borde horizontal está en map_y + 1. */
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	perform_dda_algorithm(t_game *game, t_ray *ray)
{
	/* DDA: avanza al siguiente lado de celda más cercano (X o Y). */
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = VERTICAL;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = HORIZONTAL;
		}
		if (ray->map_y < 0 || ray->map_y >= game->map.rows
			|| ray->map_x < 0 || ray->map_x >= game->map.cols
			|| game->map.grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_wall_distance(t_ray *ray, t_player *player)
{
	/* Distancia perpendicular para evitar distorsión "fish-eye". */
	if (ray->side == VERTICAL)
		ray->perp_wall_dist = (ray->map_x - player->pos_x
				+ (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->pos_y
				+ (1 - ray->step_y) / 2) / ray->raydir_y;
}
