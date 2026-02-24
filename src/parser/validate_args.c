#include "cub3d.h"

static int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

void	validate_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		exit_error("Usage: ./cub3D <map.cub>", NULL);
	if (!check_extension(argv[1]))
		exit_error("Map file must have .cub extension", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Cannot open map file", NULL);
	close(fd);
}
