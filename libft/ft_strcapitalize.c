/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcapitalize.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 17:25:01 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 17:21:58 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_numeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

static int		ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char			*ft_strcapitalize(char *str)
{
	int			i;

	if ('a' <= str[0] && str[0] <= 'z')
		str[0] = str[0] - 'a' + 'A';
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_is_alpha(str[i]))
		{
			if (ft_is_numeric(str[i - 1]))
			{
				if ('A' <= str[i] && str[i] <= 'Z')
					str[i] = str[i] - 'A' + 'a';
			}
			else if ('a' <= str[i] && str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return (str);
}
