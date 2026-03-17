/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/17 17:45:06 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture(t_game *game, mlx_texture_t **tex, char *path)
{
	*tex = mlx_load_png(path);
	if (!*tex)
		exit_error("Failed to load texture", game);
}

void	load_textures(t_game *game)
{
	load_texture(game, &game->textures.tex_no, game->textures.path_no);
	load_texture(game, &game->textures.tex_so, game->textures.path_so);
	load_texture(game, &game->textures.tex_we, game->textures.path_we);
	load_texture(game, &game->textures.tex_ea, game->textures.path_ea);
}
