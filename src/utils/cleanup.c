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

static void	cleanup_textures(t_game *game)
{
	if (game->textures.path_no)
		free(game->textures.path_no);
	if (game->textures.path_so)
		free(game->textures.path_so);
	if (game->textures.path_we)
		free(game->textures.path_we);
	if (game->textures.path_ea)
		free(game->textures.path_ea);
	if (game->textures.tex_no)
		mlx_delete_texture(game->textures.tex_no);
	if (game->textures.tex_so)
		mlx_delete_texture(game->textures.tex_so);
	if (game->textures.tex_we)
		mlx_delete_texture(game->textures.tex_we);
	if (game->textures.tex_ea)
		mlx_delete_texture(game->textures.tex_ea);
}

// REVISAR

/* static void	cleanup_images(t_game *game)
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
	if (game->file)
		free_array(game->file);
	if (game->map.grid)
		free_array(game->map.grid);
	cleanup_textures(game);
/* 	if (game->img)
	{
		cleanup_images(game);
		free(game->img);
	} */
	if (game->mlx)
		mlx_terminate(game->mlx);
}
