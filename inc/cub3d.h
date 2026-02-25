#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>
# include "libft.h"
# include "MLX42/MLX42.h"

// Dimensiones de la ventana
# define WIDTH 1280
# define HEIGHT 720

// Velocidad de movimiento y rotación
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

/* Estructura del mapa 2D */
typedef struct s_map
{
	char	**grid;			// Mapa 2D ('1' = pared, '0' = espacio vacío)
	int		width;			// Ancho del mapa
	int		height;			// Alto del mapa
}	t_map;

/* Estructura del jugador */
typedef struct s_player
{
	double	pos_x;			// Posición X en el mapa
	double	pos_y;			// Posición Y en el mapa
	double	dir_x;			// Vector dirección X
	double	dir_y;			// Vector dirección Y
	double	plane_x;		// Plano de cámara X (perpendicular a dir)
	double	plane_y;		// Plano de cámara Y
}	t_player;

/* Estructura de texturas */
typedef struct s_textures
{
	mlx_texture_t	*north;	// Textura pared norte
	mlx_texture_t	*south;	// Textura pared sur
	mlx_texture_t	*west;	// Textura pared oeste
	mlx_texture_t	*east;	// Textura pared este
}	t_textures;

/* Estructura principal del juego */
typedef struct s_game
{
	mlx_t		*mlx;		// Puntero a MLX
	mlx_image_t	*img;		// Imagen donde se renderiza
	t_map		map;		// Datos del mapa
	t_player	player;		// Datos del jugador
	t_textures	tex;		// Texturas
	int			floor_color;	// Color del suelo (RGB empaquetado)
	int			ceiling_color;	// Color del techo (RGB empaquetado)
}	t_game;

/* Estructura auxiliar para raycasting */
typedef struct s_ray
{
	double	camera_x;		// Coordenada X en el plano de cámara (-1 a 1)
	double	ray_dir_x;		// Dirección del rayo X
	double	ray_dir_y;		// Dirección del rayo Y
	int		map_x;			// Posición del rayo en el mapa (coordenada X)
	int		map_y;			// Posición del rayo en el mapa (coordenada Y)
	double	side_dist_x;	// Distancia al siguiente lado X
	double	side_dist_y;	// Distancia al siguiente lado Y
	double	delta_dist_x;	// Distancia entre lados X
	double	delta_dist_y;	// Distancia entre lados Y
	int		step_x;			// Dirección de paso en X (-1 o 1)
	int		step_y;			// Dirección de paso en Y (-1 o 1)
	int		hit;			// ¿Se golpeó una pared?
	int		side;			// ¿Qué lado se golpeó? (0 = X, 1 = Y)
	double	perp_wall_dist;	// Distancia perpendicular a la pared
	int		line_height;	// Altura de la línea a dibujar
	int		draw_start;		// Píxel donde empieza a dibujar
	int		draw_end;		// Píxel donde termina de dibujar
}	t_ray;

// Funciones del executor
void	init_game(t_game *game);
void	render_frame(void *param);
void	handle_input(void *param);
void	cast_ray(t_game *game, t_ray *ray, int x);

#endif
