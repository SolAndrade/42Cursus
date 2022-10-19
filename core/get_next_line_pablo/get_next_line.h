#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef FT_GETNEXTLINE_H
# define FT_GETNEXTLINE_H
//# define BUFFER_SIZE BUFSIZ

char *get_next_line(int fd);

#endif