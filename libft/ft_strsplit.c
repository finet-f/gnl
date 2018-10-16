/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:29:45 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 19:20:01 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_count_word(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i - 1] != c && i) ||
				(s[i + 1] == '\0' && s[i] != c))
			n++;
		i++;
	}
	return (n);
}

static int	ft_l_w(char const *s, int p, char w)
{
	int		c;

	c = 0;
	while ((!(s[p] == w) && s[p]))
	{
		p++;
		c++;
	}
	return (c);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		p;
	char	**tab;

	i = -1;
	p = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(*tab) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (++i < ft_count_word(s, c))
	{
		while (s[p] == c)
			p++;
		if (!(tab[i] = (char*)malloc(sizeof(tab) * (ft_l_w(s, p, c) + 1))))
			return (NULL);
		j = -1;
		while (++j < ft_l_w(s, p, c))
			tab[i][j] = s[j + p];
		tab[i][j] = '\0';
		p += ft_l_w(s, p, c);
	}
	tab[ft_count_word(s, c)] = 0;
	return (tab);
}
