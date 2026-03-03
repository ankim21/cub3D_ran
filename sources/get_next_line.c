/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabi-aka <rabi-aka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:58:27 by rabi-aka          #+#    #+#             */
/*   Updated: 2026/02/28 18:58:29 by rabi-aka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*clean_stash(char *stash)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0' || (stash[i] == '\n' && stash[i + 1] == '\0'))
	{
		free(stash);
		stash = NULL;
		return (stash);
	}
	else
		new = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!new)
		return (NULL);
	free(stash);
	return (new);
}

char	*ft_get_line(char **line, char **stash)
{
	int	i;
	int	n;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\0')
		i -= 1;
	*line = malloc((i + 2) * sizeof(char));
	if (!*line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	n = 0;
	while ((*stash)[i] && n <= i)
	{
		(*line)[n] = (*stash)[n];
		n++;
	}
	(*line)[n] = '\0';
	return (*line);
}

char	*stock_reader(char **stash, char *buffer)
{
	char	*temp;

	if (!*stash)
		*stash = ft_strdup(buffer);
	else if (*stash)
	{
		temp = ft_strjoin(*stash, buffer);
		if (!temp)
			return (NULL);
		free(*stash);
		*stash = temp;
		return (*stash);
	}
	if (!stash)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	return (*stash);
}

char	*reader(int fd, char **stash)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
	{
		if (*stash)
			free(*stash);
		*stash = NULL;
		free(buffer);
		return (NULL);
	}
	if (bytes == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	stock_reader(stash, buffer);
	free(buffer);
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (reader(fd, &stash))
	{
		if (stash && ft_strchr(stash, '\n'))
			break ;
	}
	if (stash)
	{
		ft_get_line(&line, &stash);
		stash = clean_stash(stash);
		return (line);
	}
	return (NULL);
}
