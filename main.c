#include "get_next_line.h"

int main(int ac, char **av)
{
  int fd;
  char str[950][950];
  
  while(get_next_line(fd, str));
}
