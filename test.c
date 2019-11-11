/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 17:22:51 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 21:43:15 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int		main()
{
	char	*line = NULL;
	int 	fd;
	int 	i = 0;

	fd = open("get_next_line.c", O_RDONLY);

	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("[%d]%s\n", i, line);
		// free(line);
	}
	printf("[%d]%s\n", i, line);
	free(line);

	fd = open("get_next_line.h", O_RDONLY);

	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("[%d]%s\n", i, line);
		free(line);
	}
	printf("[%d]%s\n", i, line);
	free(line);
}

// int		main() // Multi FD
// {
// 	char	*line = NULL;
// 	// char	*line2 = NULL;
// 	int 	fd;
// 	int 	fd2;
// 	int 	i = 0;
// 	int 	count = 0;

// 	fd2 = open("get_next_line.h", O_RDONLY);
// 	fd = open("get_next_line.c", O_RDONLY);

// 	while (count < 50)
// 	{
// 		i = get_next_line(fd, &line);
// 		printf("[%d]%s\n", i, line);
// 		free(line);

// 		i = get_next_line(fd2, &line2);
// 		printf("DEUX=[%d]%s\n", i, line2);
// 		free(line);
// 		count++;
// 	}
// 	i = get_next_line(fd, &line);
// 	printf("[%d]%s\n", i, line);
// 	free(line);
// }
