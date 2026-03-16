/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/10 00:00:00 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		map_start;

	init_game(&game);
	validate_args(argc, argv);
	parse_file(&game, argv[1]);
	map_start = parse_header(&game);
	parse_map(&game, map_start);
	init_player_dir(&game);
	init_window(&game);
	load_textures(&game);
	start_game(&game);
	mlx_loop_hook(game.mlx, ft_render, &game);
	mlx_loop_hook(game.mlx, handle_input, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
