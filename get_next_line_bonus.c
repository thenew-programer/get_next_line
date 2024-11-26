/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:45:10 by ybouryal          #+#    #+#             */
/*   Updated: 2024/11/08 22:01:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*read_line(int fd, char *buffer, char *left)
{
	ssize_t	ret;
	char	*tmp;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			if (left)
				return (free(left), NULL);
			return (NULL);
		}
		if (ret == 0)
			break ;
		buffer[ret] = '\0';
		if (!left)
			left = ft_strdup("");
		tmp = left;
		left = ft_strjoin(left, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*extract_line(char **left)
{
	char	*tmp_left;
	char	*line;
	ssize_t	len;

	len = 0;
	if (!*left || !**left)
		return (NULL);
	while ((*left)[len] && (*left)[len] != '\n')
		len++;
	if ((*left)[len] == '\n')
		line = ft_substr(*left, 0, ++len);
	else
		line = ft_strdup(*left);
	if ((*left)[len])
	{
		tmp_left = ft_strdup(*left + len);
		free(*left);
		*left = tmp_left;
	}
	else
	{
		free(*left);
		*left = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left[MAX_FD + 1] = {NULL};
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		if (left[fd])
			free(left[fd]);
		left[fd] = NULL;
		return (NULL);
	}
	left[fd] = read_line(fd, buffer, left[fd]);
	free(buffer);
	if (!left[fd])
		return (NULL);
	line = extract_line(&left[fd]);
	return (line);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	int	fd[3];
	int	line_counter;
	char	*line;

	(void)argc;
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[2], O_RDONLY);
	fd[2] = open(argv[3], O_RDONLY);
	line_counter = 1;
	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			line = get_next_line(fd[i]);
			if (!line)
				return (0);
			printf("%d  %s", line_counter, line);
			line_counter++;
			free(line);
		}
	}
}*/
