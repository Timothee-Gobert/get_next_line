/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:37:43 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/12 12:04:10 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char buffer[BUFFER_SIZE + 1] = "";
// }

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	static char	buf[BUFFER_SIZE + 1] = "";// stocke les caractères lus par read
	int			count;					// compte du nb de lectures avec read
	int			fd;						// descripteur de fichier à lire
	int			nb_read;				// stocke le retour de read
	char		*path;
	int			i;
	int			next_line_find;

	next_line_find = 0;
	path = "test.txt";
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	//	Initialise les variables de compte
	nb_read = -1;
	count = 0;
	i = 0;
	//	Boucle tant que read ne retourne pas 0 (ce qui veut dire
	//	qu'il n'y a plus rien à lire dans le fichier)
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
			return (NULL);
		buf[nb_read] = '\0';
		while (i < nb_read)
		{
			if (buf[i] == '\n')
			{
				printf("saut de ligne a - %d -", i);
			}
			i++;
		}
		i = 0;
		printf("nb read : %d\ncount : %d\n\n",nb_read, count);
		count++;
	}
	return 0;
}
