/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/03 16:42:21 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 03:30:29 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int		count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

t_gnl	*ft_create_list(int fd)
{
	t_gnl	*lst;

	if (fd < 0 || (!(lst = malloc(sizeof(t_gnl)))))
		return (NULL);
	lst->fd = fd;
	lst->content = NULL;
	lst->next = NULL;
	return (lst);
}

t_gnl	*ft_lstchr(t_gnl *list, int fd)
{
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_gnl	*ft_lstadd(t_gnl **alst, t_gnl *new)
{
	if (alst)
		new->next = *alst;
	*alst = new;
	return (*alst);
}

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = -1;
	if (!s)
		return (NULL);
	while (s[++count])
		if (s[count] == c)
			return (char *)(s + count);
	if (s[count] == c)
		return (char *)(s + count);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		count;
	char	*tab;

	count = 0;
	while (s[count])
		count++;
	if (!(tab = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	count = -1;
	while (s[++count])
		tab[count] = s[count];
	tab[count] = '\0';
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	count;
	size_t	s1_size;
	char	*tab;

	count = -1;
	s1_size = ft_strlen(s1);
	if (!(tab = (char *)malloc((s1_size + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1 && s1[++count])
		tab[count] = s1[count];
	count = -1;
	while (s2 && s2[++count])
		tab[s1_size + count] = s2[count];
	tab[s1_size + count] = '\0';
	return (tab);
}
