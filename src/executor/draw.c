#include "cub3d.h"

static mlx_texture_t	*get_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (game->tex.east);
		else
			return (game->tex.west);
	}
	else
	{
		if (ray->step_y > 0)
			return (game->tex.south);
		else
			return (game->tex.north);
	}
}

static int	get_texture_x(t_game *game, t_ray *ray, mlx_texture_t *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

static int	get_pixel_color(mlx_texture_t *tex, int x, int y)
{
	int		index;
	uint8_t	*pixel;

	index = (y * tex->width + x) * tex->bytes_per_pixel;
	pixel = &tex->pixels[index];
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}

static void	draw_textured_line(t_game *game, int x, t_ray *ray)
{
	mlx_texture_t	*tex;
	int				tex_x;
	int				tex_y;
	int				y;
	double			step;
	double			tex_pos;

	tex = get_texture(game, ray);
	tex_x = get_texture_x(game, ray, tex);
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < ray->draw_start)
			mlx_put_pixel(game->img, x, y, game->ceiling_color);
		else if (y <= ray->draw_end)
		{
			tex_y = (int)tex_pos & (tex->height - 1);
			tex_pos += step;
			mlx_put_pixel(game->img, x, y, get_pixel_color(tex, tex_x, tex_y));
		}
		else
			mlx_put_pixel(game->img, x, y, game->floor_color);
		y++;
	}
}

void	render_frame(void *param)
{
	t_game	*game;
	t_ray	ray;
	int		x;

	game = (t_game *)param;
	x = 0;
	while (x < WIDTH)
	{
		cast_ray(game, &ray, x);
		draw_textured_line(game, x, &ray);
		x++;
	}
}
