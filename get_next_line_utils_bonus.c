/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:43:30 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/12 19:43:46 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	len = ft_strlen(s);
	clone = (char *)malloc(sizeof(char) * (len + 1));
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	truelen;
	unsigned int	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		truelen = 1;
	else if (len >= slen)
		truelen = slen - start + 1;
	else
		truelen = len + 1;
	sub = (char *)malloc(truelen);
	if (!sub)
		return (NULL);
	while ((start < slen) && (i < len))
	{
		sub[i] = s[start];
		i++;
		start++;
	}	
	sub[i] = 0;
	return (sub);
}
