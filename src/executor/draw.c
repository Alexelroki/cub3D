/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/17 17:01:51 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_column(t_game *game, int x, int draw[2])
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < draw[0])
			mlx_put_pixel(game->img, x, y, game->textures.ceil_color);
		else if (y > draw[1])
			mlx_put_pixel(game->img, x, y, game->textures.floor_color);
		y++;
	}
}

static void	cast_ray(t_game *game, t_ray *ray, int x)
{
	int	draw[2];

	init_ray_data(game, ray, x);
	calculate_step_data(ray, &game->player);
	perform_dda_algorithm(game, ray);
	calculate_wall_distance(ray);
	if (ray->perp_wall_dist < 0.1)
		ray->perp_wall_dist = 0.1;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	draw[0] = (HEIGHT - ray->line_height) / 2;
	if (draw[0] < 0)
		draw[0] = 0;
	draw[1] = (HEIGHT + ray->line_height) / 2;
	if (draw[1] >= HEIGHT)
		draw[1] = HEIGHT - 1;
	draw_column(game, x, draw);
	draw_wall(game, ray, x, draw);
}

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		cast_ray(game, &ray, x);
		x++;
	}
}
