/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/19 15:23:12 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static int	check_extensionpng(char *file)
{
	char	*base;
	char	*dot;
	char	*last_dot;

	base = ft_strrchr(file, '/');
	if (base)
		base++;
	else
		base = file;
	dot = ft_strchr(base, '.');
	last_dot = ft_strrchr(base, '.');
	if (!dot || dot != last_dot)
		return (0);
	if (dot == base)
		return (0);
	if (ft_strncmp(dot, ".png", 4) != 0 || dot[4])
		return (0);
	return (1);
}

static void	parse_texture(t_game *game, char **dst, char *line)
{
	int	i;

	if (*dst)
		exit_error("Duplicate texture identifier", game);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	*dst = ft_strtrim(line + i, " \n");
	if (!*dst || ft_strlen(*dst) == 0 || !check_extensionpng(*dst))
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
		parse_color(game, &game->textures.ceil_color, line + 2);
	else
		return (0);
	return (1);
}

int	parse_header(t_game *game)
{
	int	i;

	i = 0;
	while (game->file[i])
	{
		if (is_empty_line(game->file[i]))
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
	if (game->textures.floor_color == -1 || game->textures.ceil_color == -1)
		exit_error("Missing color identifier", game);
	return (i);
}
