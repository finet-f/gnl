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
#include "libft/include/libft.h"

char *get_line(int *i, const int fd, char *rest)
{
  char buff[BUFF_SIZE + 1];

  *i = read(fd, buff, BUFF_SIZE);
  buff[*i] = '\0';
 if ((rest = ft_strjoin(rest, buff)) == NULL)
    return (NULL);
  return (rest);
}

int fill_line_modif_rest(char **line, char **rest)
{
  char *str;
  int j;
  int i;

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

char *check_n(char *rest)
{
  int     i;

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

void *replace_rest(size_t i, char *rest, char *str)
{
  char   *d;
  char   *s;

  d = rest;
  s = str;
  if (s < d)
    {
      s += i;
      d += i;
      while (i--)
	*--d = *--s;
    }
 else
   while (i--)
     *d++ = *s++;
  rest = d;
  return (rest);
}

int get_next_line(const int fd, char **line)
{
  static char *rest = "";
  char *str;
  int i;

  i = 1;
  if (line == NULL || fd < 0)
    return (-1);
  if (rest[0] == '\0' && ((rest = ft_realloc(rest)) == NULL))
    return(-1);
  while (i > 0)
    {
      if ((str = check_n(rest)) != NULL)
	{
	  *str = '\0';
	  if ((*line = ft_realloc(rest)) == NULL)
	    return (-1);
	  replace_rest(ft_strlen(str + 1) + 1, rest, str + 1);
	  return (1);
	}
      if ((rest = get_line(&i, fd, rest)) == NULL)
	return (-1); 
    }
  if (i == 0 && (ft_strlen(rest) != 0))
    i = fill_line_modif_rest(&(*line), &rest);
  return (i);
}
