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

size_t ft_strlen(const char *str)
{
    size_t ret;

    ret = 0;
    if (!str)
        return(ret);
    while(str[ret] != '\0')
        ret++;
    return (ret);
}

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

char *add_to_line(char *old_line, const char *new_part)
{
    char *expanded_line;
    size_t  len;
    size_t  i1;
    size_t  i2;

    len = ft_strlen(old_line) + ft_strlen(new_part);
    if (len == 0)
        return (NULL);
    expanded_line = (char *) malloc(sizeof(char) * (len + 1));
    if (expanded_line == NULL)
        return (NULL);
    i1 = 0;
    while(old_line != NULL && old_line[i1] != '\0')
    {
        expanded_line[i1] = old_line[i1];
        i1++;
    }
    i2 = 0;
    while(new_part[i2] != '\0')
    {
        expanded_line[i1 + i2] = new_part[i2];
        i2++;
    }
    expanded_line[i1 + i2] = '\0';
    free(old_line);
    return(expanded_line);
}

char    *get_next_line(int fd)
{
    char *line;
    char *to_store;
    int n;
	int	find_nl;

    to_store = (char *)malloc(sizeof(char) * BUFFERSIZE + 1);
    if (to_store == NULL)
		return (NULL);
    line = NULL;
	find_nl = -1;
	while (find_nl == -1)
	{
		n=read(fd, to_store, BUFFERSIZE);
		to_store[n] = '\0';
        line = add_to_line(line, to_store);
		find_nl = find_newline(to_store);
		if (n == 0 )
		{
			free(to_store);
			to_store = NULL;
			break ;
		}
	}	
    return (line);
}