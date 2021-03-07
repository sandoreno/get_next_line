/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:48:49 by acarroll          #+#    #+#             */
/*   Updated: 2021/01/20 19:53:03 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

int		string_and_remainder(int fd, char *buf, char **rem)
{
	char	*temp;
	int		count_byte;

	count_byte = 1;
	while ((ft_strchr(*rem, '\n') == NULL) && count_byte > 0)
	{
		count_byte = read(fd, buf, BUFFER_SIZE);
		if (count_byte == -1)
			return (-1);
		buf[count_byte] = '\0';
		if (*rem == NULL)
		{
			if (!(*rem = ft_strdup(buf)))
				return (-1);
		}
		else
		{
			temp = *rem;
			if (!(*rem = ft_strjoin(*rem, buf)))
				return (-1);
			free(temp);
		}
	}
	return (1);
}

int		write_to_string(char **rem, char **line)
{
	char	*position;
	char	*temp;
	int		length;

	if ((position = ft_strchr(*rem, '\n')))
	{
		length = position - *rem + 1;
		if (!(*line = malloc(sizeof(char) * length)))
			return (-1);
		ft_strlcpy(*line, *rem, length);
		temp = ft_strdup(++position);
		free(*rem);
		*rem = temp;
		return (1);
	}
	else
	{
		if (*rem)
		{
			*line = ft_strdup(*rem);
			free(*rem);
			*rem = NULL;
		}
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*g_n_l_rem = NULL;
	int			reading;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((string_and_remainder(fd, buf, &g_n_l_rem) == -1))
	{
		free(buf);
		return (-1);
	}
	free(buf);
	if ((reading = write_to_string(&g_n_l_rem, line)) == -1)
		return (-1);
	return (reading);
}
