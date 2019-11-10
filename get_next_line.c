/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/03 16:36:36 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 05:37:09 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_pretty(char **line, t_gnl *current)
{
	int		size;

	if (!ft_strchr(current->content, '\n'))
	{
		*line = ft_strdup(current->content);
		return (0);
	}
	else
	{
		size = (int)(ft_strchr(current->content, '\n') - current->content);
		*line = ft_substr(current->content, 0, size);
		current->content = ft_strdup(current->content + size + 1);
		return (1);
	}
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*tmp;
	char			buffer[BUFFER_SIZE + 1];

	if (!line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!lst && !(lst = ft_create_list(fd)))
			return (-1);
	if (!(tmp = ft_lstchr(lst, fd)) && !(tmp = ft_lstadd(&lst, ft_create_list(fd)))) // si il trouve pas il le creer
		return (-1);
	while (!ft_strchr(tmp->content, '\n') && read(fd, buffer, 265) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
	//	printf("READ %d-[%s]\n", r, buffer);
		tmp->content = ft_strjoin(tmp->content, buffer);
	}
	return (ft_pretty(line, tmp));
	// printf("%d\n", (int)(ft_strchr(tmp->content, '\n') - tmp->content));
	// printf("%s\n", tmp->content);
	// lst->content = ft_strjoin(lst->content, buffer);
	// *line = lst->content;
	// printf("%zd\n", read(fd, lst->content, BUFFER_SIZE));
	// return (1);
}

int		main()
{
	char	*line;
	int 	fd;
	int 	i = 0;

	fd = open("bible.tt", O_RDONLY);
	// fd = open("get_next_line.c", O_RDONLY);
	printf("GNL with fd=%d\n", fd);
	// get_next_line(fd, &line);
	// printf("<\n%s\n>", line);
	// get_next_line(fd, &line);
	// printf("<\n%s\n>", line);

	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s | %d\n", line, i);
		free(line);
		line = NULL;
	}
	// free(line);
	// printf("%s\n", ft_strjoin("", "\n"));
}
