#include "cub3d.h"

void	exit_error(const char *message, t_game *game)
{
	if (message)
		ft_printf("Error\n%s\n", message);
	cleanup_game(game);
	exit(EXIT_FAILURE);
}
