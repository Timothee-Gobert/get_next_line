/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inox <inox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:37:43 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/17 23:10:35 by inox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (size == 0 || i > size)
		return (size + j);
	if (!*src)
		return (i);
	j = 0;
	while (src[j] && (i + j < size - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		size -= 1;
		while (src[i] && i < size)
		{
			if (i < size)
				dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

void	ft_del_begin_and_fill_line(char *buffer,char *back, size_t i)
{
	size_t	j;

	j = 0;
	while (j <= i)
	{
		back[j] = buffer[j];
		j++;
	}
	j = 0;
	while (buffer[i] <= ft_strlen(buffer))
		buffer[j++] = buffer[i++];
}

int	ft_strchr_i(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char *line = "";
	char buffer[BUFFER_SIZE + 1];
	int nb_read; // stocke le retour de read
	size_t		i;

	nb_read = -1;
	while (nb_read != 0)
	{
		if (ft_strlen(buffer) <= 1)
		{
			nb_read = read(fd, buffer, BUFFER_SIZE);
			if (nb_read < 1 || !fd)
				return (NULL);
			buffer[nb_read] = '\0';
		}
		i = ft_strchr_i(buffer, '\n');
		line = ft_strjoin(line, ft_substr(buffer, 0, i));
		ft_del_begin_and_fill_line(buffer, line, i);
		if (i != ft_strlen(buffer))
			return(line);
	}
	return(NULL);
}
