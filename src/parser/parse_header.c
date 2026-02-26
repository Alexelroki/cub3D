#include "cub3d.h"

static void	parse_texture(t_game *game, char **dst, char *line)
{
	int	i;

	if (*dst)
		exit_error("Duplicate texture identifier", game);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	*dst = ft_strtrim(line + i, " \n");
	if (!*dst || ft_strlen(*dst == 0))
		exit_error("Invalid texture path", game);	
}

static int	parse_identifier(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_texture(game, &game->textures.path_no, line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_texture(game, &game->textures.path_so, line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_texture(game, &game->textures.path_we, line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_texture(game, &game->textures.path_ea, line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_color(game, &game->textures.floor_color, line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_color(game, &game->textures.cecil_color, line + 2);
	else
		return (0);
	return (1);
}

int	parse_header(t_game *game)
{
	int	i;

	i = 0;
	while (game->file)
	{
		if (game->file[i][0] == '\0')
		{
			i++;
			continue ;
		}
		if (!parse_identifier(game, game->file[i]))
			break ;
		i++;
	}
	if (!game->textures.path_no || !game->textures.path_so
		|| !game->textures.path_we || !game->textures.path_ea)
		exit_error("Missing texture identifier", game);
	if (!game->textures.floor_color || !game->textures.cecil_color)
		exit_error("Missing color identifier", game);
	return (i);
}
