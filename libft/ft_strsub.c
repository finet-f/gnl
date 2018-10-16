/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:50 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 15:57:55 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tr;
	size_t		i;

	tr = NULL;
	i = 0;
	if (s)
	{
		if (!(tr = (char*)malloc(sizeof(*tr) * len + 1)))
			return (NULL);
		while (i < len)
			tr[i++] = s[start++];
	}
	tr[i] = '\0';
	return (tr);
}
