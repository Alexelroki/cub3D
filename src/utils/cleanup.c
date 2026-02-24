#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
// REVISAR

/* static void	cleanup_textures(t_game *game)
{
	if (game->tex->tex_floor)
		mlx_delete_texture(game->tex->tex_floor);
	if (game->tex->tex_wall)
		mlx_delete_texture(game->tex->tex_wall);
	if (game->tex->tex_coin)
		mlx_delete_texture(game->tex->tex_coin);
	if (game->tex->tex_player)
		mlx_delete_texture(game->tex->tex_player);
	if (game->tex->tex_exit)
		mlx_delete_texture(game->tex->tex_exit);
}

static void	cleanup_images(t_game *game)
{
	if (game->img->img_floor)
		mlx_delete_image(game->mlx, game->img->img_floor);
	if (game->img->img_wall)
		mlx_delete_image(game->mlx, game->img->img_wall);
	if (game->img->img_coin)
		mlx_delete_image(game->mlx, game->img->img_coin);
	if (game->img->img_player)
		mlx_delete_image(game->mlx, game->img->img_player);
	if (game->img->img_exit)
		mlx_delete_image(game->mlx, game->img->img_exit);
} */

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
/* 	if (game->map)
		free_map_data(game->map);
	if (game->tex)
	{
		cleanup_textures(game);
		free(game->tex);
	}
	if (game->img)
	{
		cleanup_images(game);
		free(game->img);
	} */
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}
