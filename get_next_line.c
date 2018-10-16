/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfinet <flfinet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:46:44 by flfinet           #+#    #+#             */
/*   Updated: 2018/10/16 17:54:28 by flfinet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/include/libft.h"

char			*modif_rest(char *rest, int *i)
{
	char		*new;
	int			j;

	j = 0;
	new = NULL;
	new = ft_realloc(new);
	if (rest[*i] == '\n')
		*i = *i + 1;
	while (rest[*i])
	{
		new[j] = rest[*i];
		*i = *i + 1;
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
		line[*i] = &buff[k];
		*i = *i + 1;
		k++;
		if (*i == BUFF_SIZE - 1)
			*line = ft_realloc(*line);
	}
	line[*i] = NULL;
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
      printf("%s\n", rest);
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
		if (r == -1 || (r == 0 && *line == NULL))
			return (NULL);
		if (r == 0)
			return (*line);
		buff[r] = '\0';
		*line = ft_realloc(*line);
		if (get_next_lin3(line, &i, buff, rest) == 1)
			return (*line);
	}
	free(buff);
	return (*line);
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
	*line = ft_realloc(*line);
	while (rest[i] != '\n' && rest[i] != '\0')
	{
		*line[i] = rest[i];
		i++;
	}
	*line[i] = '\0';
	c = rest[i];
	rest = modif_rest(rest, &i);
	if (c == '\n')
		return (0);
	*line = ft_realloc(*line);
	get_next_line2(line, rest, i, fd);
	printf("%s", *line);
	return (0);
}
