#include "cub3d.h"

static int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

void	parse_file(t_game *game, char *file)
{
	int		fd;
	int		lines;
	int		i;
	char	*line;
	char	*trimmed;

	fd = open(file, O_RDONLY);
	lines = count_lines(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	game->file = malloc(sizeof(char *) * (lines + 1));
	if (!game->file)
		exit_error("Malloc file failed", game);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (!trimmed)
			exit_error("Malloc trimmed line failed", game);
		game->file[i++] = trimmed;
		line = get_next_line(fd);
	}
	game->file[i] = NULL;
	close(fd);
}
