/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:00:41 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/17 17:05:45 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "MLX42.h"

# define TITLE "cub3D"
# define WIDTH	800
# define HEIGHT	600
# define MOVE_SPEED 0.08
# define ROT_SPEED 0.045
# define PLAYER_RADIUS 0.2

enum	e_side
{
	VERTICAL,
	HORIZONTAL
};

typedef struct s_ray
{
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		line_height;
	int		step_x;
	int		step_y;
	int		hit; // 0 = no hit, 1 = hit
	int		side; // 0 = vertical wall, 1 = horizontal wall
}	t_ray;

typedef struct s_textures
{
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	mlx_texture_t	*tex_no;
	mlx_texture_t	*tex_so;
	mlx_texture_t	*tex_we;
	mlx_texture_t	*tex_ea;
	int				floor_color;
	int				ceil_color;
}	t_textures;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	spawn_dir; // 'N', 'S', 'E' o 'W'
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**file;
	t_textures	textures;
	t_map		map;
	t_player	player;
	int			mouse_captured;
}	t_game;

// Parser functions
void	init_game(t_game *game);
void	init_window(t_game *game);
void	load_textures(t_game *game);

void	validate_args(int argc, char **argv);

void	parse_file(t_game *game, char *file);
int		parse_header(t_game *game);
void	parse_color(t_game *game, int *dst, char *line);

void	parse_map(t_game *game, int start);
void	validate_map(t_game *game);
void	check_walls(t_game *game);

void	init_player_dir(t_game *game);
void	cleanup_game(t_game *game);
void	free_array(char **array);
void	exit_error(const char *message, t_game *game);

// Executor functions
int		start_game(t_game *game);
void	ft_render(void *param);
void	handle_input(void *param);
int		ft_can_move_to(t_game *game, double x, double y);
void	ft_move_forward(t_game *game);
void	ft_move_backward(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_rotate_left(t_game *game);
void	ft_rotate_right(t_game *game);
void	ft_rotate_by_angle(t_game *game, double angle);
void	raycasting(t_game *game);
void	init_ray_data(t_game *game, t_ray *ray, int x);
void	calculate_step_data(t_ray *ray, t_player *player);
void	perform_dda_algorithm(t_game *game, t_ray *ray);
void	calculate_wall_distance(t_ray *ray);
void	draw_wall(t_game *game, t_ray *ray, int x, int draw[2]);

#endif
