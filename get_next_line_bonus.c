/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inox <inox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:37:43 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/18 21:16:03 by inox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_del_begin(char *buffer, size_t i)
{
	size_t	j;

	j = 0;
	while (buffer[i] != '\0')
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			nb_read;
	size_t		i;

	line = NULL;
	nb_read = 1;
	while (nb_read > 0)
	{
		if (ft_strlen(buffer[fd]) < 1)
		{
			nb_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (nb_read < 0)
				return (NULL);
			buffer[fd][nb_read] = '\0';
			if ((nb_read < 1) || !fd)
				return (line);
		}
		i = ft_strchr_i(buffer[fd], '\n');
		line = ft_strjoin(line, ft_substr(buffer[fd], 0, i));
		if (i != ft_strlen(buffer[fd]))
			return (ft_del_begin(buffer[fd], i + 1), line);
		ft_del_begin(buffer[fd], i);
	}
	return (line);
}
