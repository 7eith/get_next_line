/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/03 16:36:36 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 22:19:20 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 972

int		get_next_line(int fd, char **line)
{
	static char	*str;

	str = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	str = malloc(sizeof(char) * BUFFER_SIZE);
	*line = malloc(sizeof(char) * BUFFER_SIZE);
	printf("%zd\n", read(fd, str, BUFFER_SIZE));
	int count;
	count = 0;
	if (!ft_strlen(str))
		return (0);
	while (str[count] && str[count] != '\n')
	{
		(*line)[count] = str[count];
		count++;
	}
	return (1);
}

int		main()
{
	char	*line;
	int 	fd;

	fd = open("get_next_line.c", O_RDONLY);
	printf("GNL with fd=%d\n", fd);
	get_next_line(fd, &line);
	printf("<\n%s\n>", line);
	while ((get_next_line(fd, &line)) == 1)
	{
		printf("l : %s\n", line);
		// free(line);
	}
	free(line);
}
