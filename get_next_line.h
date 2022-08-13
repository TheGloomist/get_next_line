/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/13 14:16:06 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/08/13 14:16:34 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFERSIZE
#  define BUFFERSIZE 60
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
int 	find_newline(char *line);

#endif