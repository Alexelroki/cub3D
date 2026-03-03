#include "cub3d.h"

void	exit_error(const char *message, t_game *game)
{
	if (message)
	{
		write(2, "Error\n", 6);
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
		//ft_printf("Error\n%s\n", message);
	}
	cleanup_game(game);
	exit(EXIT_FAILURE);
}
