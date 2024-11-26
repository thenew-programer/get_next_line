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
#include <fcntl.h>

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
		if (!left)
			left = ft_strdup("");
		buffer[ret] = '\0';
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
	static char	*left = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (left)
			free(left);
		return (left = NULL, left);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		if (left)
			free(left);
		return (left = NULL, left);
	}
	left = read_line(fd, buffer, left);
	free(buffer);
	if (!left)
		return (NULL);
	line = extract_line(&left);
	return (line);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	int		fd;
	int		line_counter;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (0);
	line_counter = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		printf("%d  %s", line_counter, line);
		line_counter++;
		free(line);
	}
}
#include <stdio.h>

int main()
{
		int fd;
		char	*s;
		fd = open("fsoares/read_error.txt", O_RDONLY);
		if (fd < 0)
				return (1);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		while ((s = get_next_line(fd)) != NULL)
				free(s);
		close(fd);
		printf("\n\n");
		fd = open("fsoares/read_error.txt", O_RDONLY);
		if (fd < 0)
				return (1);
		do {
				s = get_next_line(fd);
				if (!s)
						continue;
				printf("%s", s);
				free(s);
		} while (s != NULL);
		return (0);
}*/
