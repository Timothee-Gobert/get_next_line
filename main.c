/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:51:46 by inox              #+#    #+#             */
/*   Updated: 2025/11/18 11:21:36 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char const *argv[])
{
	int	fd;
	int	i;
	char *line;

	if (argc != 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	i = 0;
	while (i < atoi(argv[2]))
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		i++;
	}
	return 0;
}
