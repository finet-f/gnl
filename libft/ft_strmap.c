/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:14 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:37:56 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*ptr_tab;

	ptr_tab = NULL;
	i = 0;
	if (s && f)
	{
		if (!(ptr_tab = (char*)malloc(sizeof(*ptr_tab) * ft_strlen(s) + 1)))
			return (NULL);
		while (i < ft_strlen(s))
		{
			ptr_tab[i] = f(s[i]);
			i++;
		}
	}
	ptr_tab[i] = '\0';
	return (ptr_tab);
}
