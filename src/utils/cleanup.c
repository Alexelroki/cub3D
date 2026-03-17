/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/17 17:04:07 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->file)
		free_array(game->file);
	if (game->map.grid)
		free_array(game->map.grid);
	cleanup_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
