/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:37 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:31:14 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_strnew(size_t size)
{
	void	*str;
	int		i;

	i = 0;
	size++;
	if (!(str = (void*)malloc(sizeof(*str) * size)))
		return (NULL);
	while (size--)
	{
		(*(unsigned char*)(str + i)) = 0;
		i++;
	}
	return (str);
}
