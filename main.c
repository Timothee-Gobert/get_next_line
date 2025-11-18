/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:51:46 by inox              #+#    #+#             */
/*   Updated: 2025/11/18 16:22:06 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	main(int argc, char const *argv[])
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	if (argc != 3)
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// 	i = 0;
// 	while (i < atoi(argv[2]))
// 	{
// 		line = get_next_line(fd);
// 		printf("%s\n", line);
// 		free(line);
// 		i++;
// 	}
// 	return (0);
// }

int main()
{
	int		test = open("get_next_line.c", O_RDONLY);
	int		test2 = open("test.txt", O_RDONLY);
	int		test3 = open("one_line_no_nl.txt", O_RDONLY);
	char	*next = NULL;
	int		i = 0;

	while (i < 100)
	{
		next = get_next_line(test);
		printf("%s", next);
		free(next);
		printf("\n");
		next = get_next_line(test2);
		printf("%s", next);
		free(next);
		printf("\n");
		next = get_next_line(test3);
		printf("%s", next);
		free(next);
		printf("\n");
		i++;
	}
	if (test >= 0)
	{
		close(test);
	}
	if (test2 >= 0)
	{
		close (test2);
	}
	if (test3 >= 0)
	{
		close (test3);
	}
}