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

int	get_next_lin3(char **list, int *i, int j,  char buff[BUFF_SIZE + 1], char *rest)
{
  int	k;

  k = 0;
  while (buff[k] != '\0' && buff[k] != '\n')
    {
      list[j][*i] = buff[k];
      *i = *i + 1;
      k++;
    }
  list[j][*i] = '\0';
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

char	*get_next_line2(char **list, char *rest, int i, int j, int fd)
{
  int	r;
  char	buff[BUFF_SIZE + 1];

  while (1)
    {
      r = read(fd, buff, BUFF_SIZE);
      if (r == -1 || (r == 0 && list[j] == '\0'))
	return (NULL);
      if (r == 0)
	return (list[j]);
      buff[r] = '\0';
      list[j] = ft_realloc(list[j]);
      if (get_next_lin3(&list[j], &i, j,  buff, rest) == 1)
	return (list[j]);
    }
  return (list[j]);
}

int		get_next_line(const int fd, char **list)
{
  static char	*rest;
  static int j;
  int		i;
  char		c;

  if (rest == NULL)
    {
      rest = ft_realloc(rest);
      rest[0] = 0;
          }
  i = 0;
  list[j] = ft_realloc(list[j]);
  while (rest[i] != '\n' && rest[i] != '\0')
    {
      list[j][i] = rest[i];
      i++;
    }
  list[j][i] = '\0';
  c = rest[i];
  rest = modif_rest(rest, i);
  if (c == '\n')
    return (0);
  list[j] = ft_realloc(list[j]); 
  get_next_line2(&list[j], rest, i, j, fd);
  printf("%s\n", list[j]);
  return (get_next_line(fd, &list[j++]));
 }
