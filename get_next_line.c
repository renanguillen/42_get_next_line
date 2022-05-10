/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:25:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/11 00:19:21 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*ft_strjoin(char const *s1, char const *s2)
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

static char	*ft_badsplit(char **line_static)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	if (!line_static[0])
		return (NULL);
	while (line_static[0][i] != '\n' && line_static[0][i] != '\0')
		i++;
	line = ft_substr(*line_static, 0, (i + 1));
	temp = ft_strdup(*line_static);
	free(*line_static);
	*line_static = ft_substr(temp, (i + 1), ft_strlen(temp));
	free(temp);
	if (!ft_strchr(line, '\n'))
	{
		free(line_static[0]);
		line_static[0] = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*found;
	char		*temp;
	static char	*line_static;
	int			file_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	found = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	file_read = read (fd, found, BUFFER_SIZE);
	while (file_read)
	{
		found[file_read] = 0;
		if (line_static == NULL)
			line_static = ft_strdup(found);
		else
		{
			temp = ft_strjoin(line_static, found);
			free(line_static);
			line_static = temp;
		}
		if (ft_strchr(line_static, '\n'))
			break ;
		file_read = read (fd, found, BUFFER_SIZE);
	}
	return (free(found), ft_badsplit(&line_static));
}

// int	main(void)
// {
// 	char	*gnl;
// 	int		fd;

// 	fd = open("file", O_RDONLY);
// 	gnl = get_next_line(fd);
// 	while (gnl)
// 	{
// 		printf("%s", gnl);
// 		free(gnl);
// 		gnl = get_next_line(fd);
// 	}
// 	printf("\n");
// 	return (0);
// }
