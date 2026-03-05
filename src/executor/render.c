#include "cub3d.h"

void    render(t_game *game)
{
    int		i;
    int		j;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.grid[i][j] == '1')
				draw_square(game, i, j, 0x0000FFFF);
			else if (i == (int)game->player.pos_y && j == (int)game->player.pos_x)
				draw_square(game, i, j, 0xFF0000FF);
			else
				draw_square(game, i, j, 0x000000FF);
			j++;
		}
		i++;
	}
}

void	ft_render(void *param)
{
    t_game	*game;

    game = (t_game *)param;
    raycasting(game);
}
