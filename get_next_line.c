/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 10:57:18 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 10:32:26 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char			*get_line(int *i, const int fd, char *rest)
{
	char		buff[BUFF_SIZE + 1];
	char		*str;

	*i = read(fd, buff, BUFF_SIZE);
	buff[*i] = '\0';
	str = rest;
	if ((rest = ft_strjoin(rest, buff)) == NULL)
		return (NULL);
	free(str);
	if (rest == 0)
		return (NULL);
	return (rest);
}

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

int				fill_line_modif_rest(char **line, char **rest)
{
	char		*str;
	int			j;
	int			i;

	i = 0;
	j = 0;
	if ((*line = ft_realloc(*rest)) == NULL)
		return (-1);
	while (rest[i])
		i++;
	str = *rest;
	while (i > 0)
	{
		str[j] = '\0';
		j++;
		i--;
	}
	*rest = str;
	return (1);
}

char			*check_n(char *rest)
{
	int			i;

	i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
			return (&(rest[i]));
		i++;
	}
	if (rest[i] == '\n')
		return (&(rest[i]));
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rest = "";
	char		*str;
	int			i;

	i = 1;
	if (line == NULL || fd < 0)
		return (-1);
	if (rest[0] == '\0' && ((rest = ft_realloc(rest)) == NULL))
		return (-1);
	while (i > 0)
	{
		if ((str = check_n(rest)) != NULL)
		{
			*str = '\0';
			if ((*line = ft_realloc(rest)) == NULL)
				return (-1);
			ft_memmove(rest, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if ((rest = get_line(&i, fd, rest)) == 0)
			return (-1);
	}
	if (i == 0 && ft_strlen(rest) != 0)
		i = fill_line_modif_rest(&(*line), &rest);
	return (i);
}
