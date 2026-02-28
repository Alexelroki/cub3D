/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:44:19 by albarrei          #+#    #+#             */
/*   Updated: 2025/03/01 16:05:31 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memoryfree(char **whatever)
{
	if (whatever && *whatever)
	{
		free(*whatever);
		*whatever = NULL;
	}
}

static char	*ft_extract_line(char **storage)
{
	char	*line;
	char	*new_storage;
	int		i;

	if (!*storage || **storage == '\0')
		return (NULL);
	i = 0;
	while ((*storage)[i] != '\0' && (*storage)[i] != '\n')
		i++;
	line = ft_substr(*storage, 0, i + ((*storage)[i] == '\n'));
	if (!line)
		return (NULL);
	if ((*storage)[i] == '\n')
		new_storage = ft_substr(*storage, i + 1, ft_strlen(*storage) - i - 1);
	else
		new_storage = ft_strdup("");
	if (!new_storage)
		return (NULL);
	free(*storage);
	*storage = new_storage;
	return (line);
}

static char	*ft_update_storage(char *storage, char *buffer)
{
	char	*temp;

	if (!buffer)
		return (storage);
	if (!storage)
	{
		storage = ft_strdup(buffer);
		if (!storage)
			return (NULL);
		return (storage);
	}
	temp = storage;
	storage = ft_strjoin(temp, buffer);
	free(temp);
	return (storage);
}

static int	ft_read_and_update_storage(int fd, char **storage, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		ft_memoryfree(storage);
		return (-1);
	}
	if (bytes_read == 0)
	{
		if (!*storage || **storage == '\0')
		{
			ft_memoryfree(storage);
			return (0);
		}
		return (0);
	}
	buffer[bytes_read] = '\0';
	*storage = ft_update_storage(*storage, buffer);
	if (!*storage)
		return (-1);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX] = {NULL};
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(storage[fd], '\n'))
	{
		bytes_read = ft_read_and_update_storage(fd, &storage[fd], buffer);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (ft_extract_line(&storage[fd]));
		}
	}
	free(buffer);
	return (ft_extract_line(&storage[fd]));
}
