/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 16:28:43 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/11/19 16:19:33 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	if (!str)
		return (ret);
	while (str[ret] != '\0')
		ret++;
	return (ret);
}

char	*read_error(char *to_free)
{
	free(to_free);
	return (NULL);
}

void	offset(char *to_store, int find_nl)
{
	int	i;

	i = 0;
	while (to_store[i + find_nl] != '\0')
	{
		to_store[i] = to_store[i + find_nl];
		i++;
	}
	while (to_store[i] != '\0')
	{
		to_store[i] = '\0';
		i++;
	}
}
