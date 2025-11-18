/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:37:43 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/18 14:57:20 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			nb_read;
	size_t		i;

	line = NULL;
	nb_read = 1;
	while (nb_read > 0)
	{
		if (ft_strlen(buffer) < 1)
		{
			nb_read = read(fd, buffer, BUFFER_SIZE);
			if (nb_read < 0)
				return (NULL);
			buffer[nb_read] = '\0';
			if ((nb_read < 1) || !fd)
				return (line);
		}
		i = ft_strchr_i(buffer, '\n');
		line = ft_strjoin(line, ft_substr(buffer, 0, i));
		if (i != ft_strlen(buffer))
			return (ft_del_begin(buffer, i + 1), line);
		ft_del_begin(buffer, i);
	}
	return (line);
}
