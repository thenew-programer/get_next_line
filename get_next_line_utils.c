/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:13:24 by ybouryal          #+#    #+#             */
/*   Updated: 2024/10/31 10:05:06 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, size_t *idx)
{
	char	c;
	int		ret;

	while (c != 10 && (*idx) < BUFFER_SIZE)
	{
		ret  = read(fd, &c, 1);
		if (ret == -1)
			return (buffer);
		buffer[(*idx)++] = c;
	}
	buffer[(*idx)] = c;
	return (buffer);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	while (--n)
		tmp[n] = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp1;
	const unsigned char	*tmp2;
	size_t				i;

	tmp1 = (unsigned char *)dest;
	tmp2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dest);
}
