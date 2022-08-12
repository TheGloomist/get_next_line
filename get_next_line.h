#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFERSIZE
#  define BUFFERSIZE 60
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);

#endif