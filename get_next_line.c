#include "get_next_line.h"

int find_newline(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
        i++;
    if (line[i] == '\n')
        return(i);
    else
        return(-1);
}

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