/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:28:14 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:30:23 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*str;
	int		i;

	i = 0;
	if (!(str = (void*)malloc(sizeof(*str) * size)))
		return (NULL);
	while (size--)
	{
		(*(unsigned char*)(str + i)) = 0;
		i++;
	}
	return (str);
}
