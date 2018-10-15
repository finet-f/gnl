/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 10:57:18 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 16:21:52 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char			*ft_realloc(char *str)
{
	char		*new;
	int			l;
	int			i;

	i = 0;
	l = 0;
	if (str == NULL || str[0] == 0)
		l = 1;
	else
		while (str[l])
			l++;
	new = malloc(sizeof(char) * (l * BUFF_SIZE + 1));
	if (new == NULL)
		return (NULL);
	if (str != NULL)
	{
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}

char			*modif_rest(char *rest, int i)
{
	char		*new;
	int			j;

	j = 0;
	new = NULL;
	new = ft_realloc(new);
	if (rest[i] == '\n')
		i++;
	while (rest[i])
	{
		new[j] = rest[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

int				get_next_lin3(char **line, int *i, char buff[BUFF_SIZE + 1],
		char *rest)
{
	int			k;

	k = 0;
	while (buff[k] != '\0' && buff[k] != '\n')
	{
		line[0][*i] = buff[k];
		*i = *i + 1;
		k++;
	}
	line[0][*i] = '\0';
	if (buff[k] == '\n')
	{
		*i = 0;
		k++;
		while (buff[k])
		{
			rest[*i] = buff[k];
			*i = *i + 1;
			k++;
		}
		rest[*i] = '\0';
		return (1);
	}
	return (0);
}

char			*get_next_line2(char **line, char *rest, int i, int fd)
{
	int			r;
	char		buff[BUFF_SIZE + 1];

	while (1)
	{
		r = read(fd, buff, BUFF_SIZE);
		if (r == -1 || (r == 0 && line[0] == '\0'))
			return (NULL);
		if (r == 0)
			return (line[0]);
		buff[r] = '\0';
		line[0] = ft_realloc(line[0]);
		if (get_next_lin3(&line[0], &i, buff, rest) == 1)
			return (line[0]);
	}
	return (line[0]);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rest;
	int			i;
	char		c;

	if (rest == NULL)
	{
		rest = ft_realloc(rest);
		rest[0] = 0;
	}
	i = 0;
	if ((line == malloc(sizeof(char*) * 150) == 0))
 	  return (-1);
	line[0] = ft_realloc(line[0]);
	while (rest[i] != '\n' && rest[i] != '\0')
	{
		line[0][i] = rest[i];
		i++;
	}
	line[0][i] = '\0';
	c = rest[i];
	rest = modif_rest(rest, i);
	if (c == '\n')
		return (0);
	printf("%s\n", line[0]);
	line[0] = ft_realloc(line[0]);
	printf("%s\n", line[0]);
	get_next_line2(&line[0], rest, i, fd);
	return (get_next_line(fd, line));
}
