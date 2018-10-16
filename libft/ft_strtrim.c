/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:53 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:31:19 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t				end;
	unsigned int		start;
	char				*str;

	start = -1;
	if (!s)
		return (0);
	end = ft_strlen(s) - 1;
	while (s[++start] == ' ' || s[start] == '\n' || s[start] == '\t')
		if (start == end)
		{
			if (!(str = (char*)malloc(sizeof(*str))))
				return (NULL);
			str[0] = '\0';
			return (str);
		}
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	end = end - start + 1;
	if (!(str = ft_strsub(s, start, end)))
		return (NULL);
	str[end] = '\0';
	return (str);
}
