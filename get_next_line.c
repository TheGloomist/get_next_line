#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char *line;
    int n;

    line = (char *)malloc(sizeof(char) * BUFFERSIZE + 1);
    n=read(fd, line, BUFFERSIZE);
    line[n] = '\0';
    if (n == 0)
    {
        free(line);
        line = NULL;
    }
    
    return (line);
}