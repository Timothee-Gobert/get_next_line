/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:36:20 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/12 12:00:23 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c, int find_new_line)
{
	size_t	i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (i <= ft_strlen(s)) // + 1 ?
	{
		if ((unsigned char)p[i] == (unsigned char)c)
		{
			find_new_line = 1;
			return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (s == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * i + 1);
	i = 0;
	if (dest == NULL)
		return (NULL);
	else
	{
		while (s[i])
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s_len;
	char	*joined;

	s_len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc(sizeof(char) * s_len + 1);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	ft_strlcat(joined, s2, s_len + 1);
	return (joined);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}