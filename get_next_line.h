/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flfinet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 17:43:54 by flfinet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 14:06:11 by flfinet     ###    #+. /#+    ###.fr     */
/*   Updated: 2018/10/22 16:29:45 by flfinet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

# define BUFF_SIZE 100

int	get_next_line(const int fd, char **line);

#endif
