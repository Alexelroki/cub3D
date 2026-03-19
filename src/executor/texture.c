/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponce-g <dponce-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/19 13:48:12 by dponce-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*get_texture(t_game *game, t_ray *ray)
{
	if (ray->side == VERTICAL)
	{
		if (ray->step_x > 0)
			return (game->textures.tex_ea);
		return (game->textures.tex_we);
	}
	if (ray->step_y > 0)
		return (game->textures.tex_so);
	return (game->textures.tex_no);
}

static uint32_t	get_pixel_color(mlx_texture_t *tex, int x, int y)
{
	int	i;

	i = (y * tex->width + x) * 4;
	return ((tex->pixels[i] << 24) | (tex->pixels[i + 1] << 16)
		| (tex->pixels[i + 2] << 8) | tex->pixels[i + 3]);
}

static int	get_tex_x(t_ray *ray, t_player *p, mlx_texture_t *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == VERTICAL)
		wall_x = p->pos_y + ray->perp_wall_dist * ray->raydir_y;
	else
		wall_x = p->pos_x + ray->perp_wall_dist * ray->raydir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if (ray->side == VERTICAL && ray->raydir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == HORIZONTAL && ray->raydir_y < 0)
		tex_x = tex->width - tex_x - 1;
	if (tex_x < 0 || tex_x >= (int)tex->width)
		tex_x = 0;
	return (tex_x);
}

void	draw_wall(t_game *game, t_ray *ray, int x, int draw[2])
{
	mlx_texture_t	*tex;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				y;

	tex = get_texture(game, ray);
	tex_x = get_tex_x(ray, &game->player, tex);
	step = (double)tex->height / ray->line_height;
	tex_pos = (draw[0] - HEIGHT / 2 + ray->line_height / 2) * step;
	y = draw[0];
	while (y <= draw[1])
	{
		if ((int)tex_pos >= 0 && (int)tex_pos < (int)tex->height)
			mlx_put_pixel(game->img, x, y,
				get_pixel_color(tex, tex_x, (int)tex_pos));
		tex_pos += step;
		y++;
	}
}
