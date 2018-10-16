/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 16:06:05 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:08:50 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tr = NULL;
	if (s1 && s2)
	{
		if (!(tr = (char*)malloc(sizeof(*tr) * (ft_strlen(s1) +
							ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i])
		{
			tr[i] = s1[i];
			i++;
		}
		while (s2[j])
			tr[i++] = s2[j++];
		tr[i] = '\0';
	}
	return (tr);
}
