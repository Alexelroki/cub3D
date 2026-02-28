#include "cub3d.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
	return (1);	
}

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
	{
		free_array(rgb);
		exit_error("Invalid color format", game);
	}
	if (!is_valid_number(rgb[0]) || !is_valid_number(rgb[1])
		|| !is_valid_number(rgb[2]))
	{
		free_array(rgb);
		exit_error("Invalid color value", game);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array(rgb);
	validate_range(game, r, g, b);
	*dst = rgb_to_int(r, g, b);
}
