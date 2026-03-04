#include "cub3d.h"

void	ft_move_forward(t_game *game)
{
	if (game->player.pos_y > 1 && game->map.grid[(int)game->player.pos_y - 1][(int)game->player.pos_x] != '1')
		game->player.pos_y -= 0.25;
}

void	ft_move_backward(t_game *game)
{
	if (game->player.pos_y < game->map.rows && game->map.grid[(int)game->player.pos_y + 1][(int)game->player.pos_x] != '1')
		game->player.pos_y += 0.25;
}

void	ft_move_left(t_game *game)
{
	if (game->player.pos_x > 1 && game->map.grid[(int)game->player.pos_y][(int)game->player.pos_x - 1] != '1')
		game->player.pos_x -= 0.25;
}

void	ft_move_right(t_game *game)
{
	if (game->player.pos_x < game->map.cols && game->map.grid[(int)game->player.pos_y][(int)game->player.pos_x + 1] != '1')
		game->player.pos_x += 0.25;
}

/*void	ft_rotate_right(t_game *game)
{
	if (game->player.pos_y > 1 && game->grid[game->player.pos_y - 1][game->player,pos_x] != '1')
		game->player.pos_y -= 1.0
}

void	ft_rotate_left(t_game *game)
{
	if (game->player.pos_y > 1 && game->grid[game->player.pos_y - 1][game->player,pos_x] != '1')
		game->player.pos_y -= 1.0
}*/

void    handle_input(void *param)
{
    t_game	*game;

    game = (t_game *)param;/* 
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx); */
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		ft_move_forward(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		ft_move_backward(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		ft_move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		ft_move_right(game);
}
