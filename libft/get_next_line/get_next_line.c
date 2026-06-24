/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:42:41 by fgreiff           #+#    #+#             */
/*   Updated: 2025/06/20 10:58:14 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_buffer(int fd, char *stash, char *buffer)
{
	ssize_t	read_ret;
	char	*temp;

	read_ret = 1;
	while (read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (read_ret == 0)
			break ;
		buffer[read_ret] = 0;
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*ft_set_line(char *line)
{
	char	*stash;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stash == 0 || *stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line [i + 1] = 0;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buffer);
		buffer = NULL;
		stash = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	stash = ft_fill_buffer(fd, stash, buffer);
	line = stash;
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = ft_set_line(line);
	return (line);
}
