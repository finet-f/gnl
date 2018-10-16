#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
  ac = 0;
  av = NULL;
  int fd;
  char *line;

  fd = 0;
  while(!get_next_line(fd, &line));
}
