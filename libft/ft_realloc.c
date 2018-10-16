/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 17:27:27 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 17:45:13 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_realloc(char *str)
{
	char	*new;
	int		l;
	int		i;

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
