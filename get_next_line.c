/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:25:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/05 23:14:03 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*aux_dst;
	char	*aux_src;

	i = 0;
	if (!dst && !src)
		return (NULL);
	aux_dst = (char *)dst;
	aux_src = (char *)src;
	while (i < n)
	{
		aux_dst[i] = aux_src[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*clone;
	size_t	len;

	len = ft_strlen(s) + 1;
	clone = (char *)malloc(len * sizeof(char));
	if (!clone)
		return (NULL);
	clone[len] = 0;
	ft_memcpy(clone, s, len);
	return (clone);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	if (c > 255)
		return ((void *)s);
	aux = (char *)s;
	while (*aux)
	{
		if (*aux == c)
			return (aux);
		aux++;
	}
	if (*aux == c)
		return (aux);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat = (char *)malloc(len * sizeof(char));
	if (!cat)
		return (NULL);
	cat[len] = 0;
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		cat[i] = s2[j];
		j++;
		i++;
	}
	cat[i] = 0;
	return (cat);
}

char	*get_next_line(int fd)
{
	char		*found;
	char		*temp;
	static char	*line;
	int			file_read;

	found = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	file_read = read (fd, found, BUFFER_SIZE);
	while (file_read)
	{
		if (line == NULL)
			line = ft_strdup(found);
		else
		{
			temp = ft_strjoin(line, found);
			free(line);
			line = temp;
		}
		if (ft_strchr(line, '\n'))
			break ;
		file_read = read (fd, found, BUFFER_SIZE);
	}
	return (line);
}

// int main()
// {
// 	char *gnl;
// 	int fd;
// 	fd = open("file", O_RDONLY);
// 	gnl = get_next_line(fd);
// 	printf("gnl:%s", gnl);
// }