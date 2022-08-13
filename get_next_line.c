/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/13 14:15:50 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/08/13 15:04:43 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	int	find_nl;
	int eof;

    line = (char *)malloc(sizeof(char) * BUFFERSIZE + 1);
    if (line == NULL)
		return (NULL);
	eof = 0;
	find_nl = -1;
	while (!eof && find_nl == -1)
	{
		n=read(fd, line, BUFFERSIZE);
		line[n] = '\0';
		// printf("%s\n", line);
		find_nl = find_newline(line);
		if (n == 0)
		{
			free(line);
			line = NULL;
			eof = 1;
		}
	}	
    return (line);
}