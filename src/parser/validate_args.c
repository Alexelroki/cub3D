/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dponce-g <dponce-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by albarrei          #+#    #+#             */
/*   Updated: 2026/03/19 13:37:03 by dponce-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_extension(char *file)
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
	if (ft_strncmp(dot, ".cub", 4) != 0 || dot[4])
		return (0);
	return (1);
}

void	validate_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		exit_error("Usage: ./cub3D <map.cub>", NULL);
	if (!check_extension(argv[1]))
		exit_error("Map file must be named 'name.cub'", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error("Cannot open map file", NULL);
	close(fd);
}
