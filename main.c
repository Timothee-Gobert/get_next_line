/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:51:46 by inox              #+#    #+#             */
/*   Updated: 2025/11/18 18:05:46 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char const *argv[])
{
	int		fd;
	int		i;
	char	*line;

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
	return (0);
}

// int main()
// {
// 	int		fd_test_1 = open("get_next_line.c", O_RDONLY);
// 	int		fd_test_2 = open("test.txt", O_RDONLY);
// 	int		fd_test_3 = open("one_line_no_nl.txt", O_RDONLY);
// 	char	*next = NULL;
// 	int		i = 0;

// 	setbuf(stdout, NULL);  // désactive le buffering sur stdout
// 	while (i < 30)
// 	{
// 		next = get_next_line(fd_test_1);
// 		printf("%s", next);
// 		free(next);
// 		printf("\n");
// 		next = get_next_line(fd_test_2);
// 		printf("%s", next);
// 		free(next);
// 		printf("\n");
// 		next = get_next_line(fd_test_3);
// 		printf("%s", next);
// 		free(next);
// 		printf("\n");
// 		i++;
// 	}
// 	if (fd_test_1 >= 0)
// 	{
// 		close(fd_test_1);
// 	}
// 	if (fd_test_2 >= 0)
// 	{
// 		close (fd_test_2);
// 	}
// 	if (fd_test_3 >= 0)
// 	{
// 		close (fd_test_3);
// 	}
// }