/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 18:09:38 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:11:30 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	r;
	long long	n;
	long long	p;

	r = 0;
	n = 0;
	p = 0;
	while (str[p] == '\t' || str[p] == '\n' || str[p] == '\r' ||
			str[p] == '\v' || str[p] == '\f' || str[p] == ' ' ||
			(str[p] == '+' && (str[p + 1] != '+' &&
					str[p + 1] != '-')))
		p++;
	if (str[p] == '-')
	{
		n = -1;
		p++;
	}
	while (str[p] >= '0' && str[p] <= '9')
	{
		r = r * 10 + str[p] - '0';
		p++;
	}
	if (n)
		r = -r;
	return (r);
}
