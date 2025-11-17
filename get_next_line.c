/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:37:43 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/17 18:44:07 by tgobert          ###   ########.fr       */
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
	while (j < i)
	{
		back[j] = buffer[j];
		j++;
	}
	j = 0;
	while (i <= ft_strlen(buffer))
		buffer[j++] = buffer[i++];
}

int	ft_find_next_line(const char *s, int c)
{
	size_t	i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1] = "";// stocke la lecture de read
	int			nb_read;				// stocke le retour de read
	char		*back;
	size_t		i;

	back = "";
	nb_read = -1;
	while (nb_read != 0)
	{
		if (ft_strlen(buffer) < 2)
		{
			nb_read = read(fd, buffer, BUFFER_SIZE);
			if (nb_read < 1 || !fd)
				return (NULL);
			buffer[nb_read] = '\0';
		}
		i = ft_find_next_line(buffer, '\n');
		back = ft_strjoin(back, ft_substr(buffer, 0, i));
		ft_del_begin_and_fill_line(buffer, back, i);
		if (i != ft_strlen(buffer))
			return(back);
	}
	return(NULL);
}
