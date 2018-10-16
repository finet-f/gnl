/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:32:24 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 15:58:16 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr_tab;

	ptr_tab = NULL;
	i = 0;
	if (s && f)
	{
		if (!(ptr_tab = (char*)malloc(sizeof(*ptr_tab) * ft_strlen(s) + 1)))
			return (NULL);
		while (i < (unsigned int)(ft_strlen(s)))
		{
			ptr_tab[i] = f(i, s[i]);
			i++;
		}
	}
	ptr_tab[i] = '\0';
	return (ptr_tab);
}
