/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:48:45 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/14 13:51:35 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (*(s + i) != c && *(s + i) != '\0')
		i++;
	if (*(s + i) == c)
		return ((char*)(s + i));
	else
		return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i != n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}

char	*ft_strdup(const char *s1)
{
	size_t			len;
	unsigned char	*mem;

	len = ft_strlen(s1) + 1;
	if (!(mem = malloc(len * sizeof(char))))
		return (NULL);
	mem = ft_memcpy(mem, s1, len);
	return ((char*)mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	size_t	s1_len;
	char	*memory;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	if (!(memory = malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (i != s1_len)
	{
		*(memory + i) = *s1++;
		i++;
	}
	while (i != len)
	{
		*(memory + i) = *s2++;
		i++;
	}
	*(memory + len) = '\0';
	return (memory);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		len;
	size_t	i;

	i = 0;
	if (src == NULL)
		return ((size_t)NULL);
	len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (*(src + i) != '\0' && i < dstsize - 1)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (len);
}
