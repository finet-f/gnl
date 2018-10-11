/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 10:57:18 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:01:15 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_realloc(char *str)
{
  char	*new;
  int	l;
  int	i;

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

char	*modif_rest(char *rest, int i)
{
  char	*new;
  int	j;

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

int	get_next_lin3(char **list, int *i, char buff[BUFF_SIZE + 1], char *rest)
{
  int	j;

  j = 0;
  while (buff[j] != '\0' && buff[j] != '\n')
    {
      list[0][*i] = buff[j];
      *i = *i + 1;
      j++;
    }
  list[0][*i] = '\0';
  if (buff[j] == '\n')
    {
      *i = 0;
      j++;
      while (buff[j])
	{
	  rest[*i] = buff[j];
	  *i = *i + 1;
	  j++;
	}
      rest[*i] = '\0';
      return (1);
    }
  return (0);
}

char	*get_next_line2(char **list, char *rest, int i, int fd)
{
  int	r;
  char	buff[BUFF_SIZE + 1];

  while (1)
    {
      r = read(fd, buff, BUFF_SIZE);
      if (r == -1 || (r == 0 && list[0] == '\0'))
	return (NULL);
      if (r == 0)
	return (list[0]);
      buff[r] = '\0';
      list[0] = ft_realloc(list[0]);
      if (get_next_lin3(&list[0], &i, buff, rest) == 1)
	return (list[0]);
    }
  return (list[0]);
}

int		get_next_line(const int fd, char **list)
{
  static char	*rest;
  int		i;
  char		c;

  if (rest == NULL)
    {
      rest = ft_realloc(rest);
      rest[0] = 0;
    }
  i = 0;
  list[0] = ft_realloc(list[0]);
  while (rest[i] != '\n' && rest[i] != '\0')
    {
      list[0][i] = rest[i];
      i++;
    }
  list[0][i] = '\0';
  c = rest[i];
  rest = modif_rest(rest, i);
  if (c == '\n')
    return (0);
  list[0] = ft_realloc(list[0]);
  get_next_line2(&list[0], rest, i, fd);
  printf("%s\n", list[0]);
  return (0);
}
