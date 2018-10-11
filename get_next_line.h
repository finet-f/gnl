#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef BUFF_SIZE
#  define BUFF_SIZE (5)
# endif /* !BUFF_SIZE */

int	get_next_line(const int fd, char **list);

#endif /* GET_NEXT_LINE_H_ */
