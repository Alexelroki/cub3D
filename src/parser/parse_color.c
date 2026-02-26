#include "cub3d.h"

static void	validate_range(t_game *game, int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error("Color value out of range [0, 255]", game);
}

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	parse_color(t_game *game, int *dst, char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (*dst != -1)
		exit_error("Duplicate color identifier", game);
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		exit_error("Invalid color format", game);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	validate_range(game, r, g, b);
	*dst = rgb_to_int(r, g, b);
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
}
