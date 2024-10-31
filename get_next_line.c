/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:12:05 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/31 10:35:19 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(const char *buffer, size_t start)
{
	size_t	len;
	char	*line;

	len = ft_strlen(&buffer[start]);
	line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, &buffer[start], len + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	static size_t	buf_idx = 0;
	size_t			start;

	if (fd < 3 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	start = buf_idx;
	read_line(fd, buffer, &buf_idx);
	if (start == buf_idx)
		return (NULL);
	if (buf_idx == BUFFER_SIZE)
	{
		free(buffer);
		return (NULL);
	}
	return (get_line(buffer, start));
}
/*
	// return (&buffer[start]);
int main()
{
	int		fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY);
	if (fd < 3)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		for (int i = 0; line[i - 1] != 10 && line[i]; i++)
			printf("%c", line[i]);
		free(line);
	}
}*/
