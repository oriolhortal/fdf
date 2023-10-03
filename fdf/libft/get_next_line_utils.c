/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:17:08 by ohortal-          #+#    #+#             */
/*   Updated: 2023/05/26 11:58:27 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*my_strchr(const char *s, int c)
{
	if (s && *s)
	{
		while (*s && *s != (char)c)
			s++;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}

char	*my_strjoin(char *buffer, char *tail, ssize_t size)
{
	int		i;
	int		j;
	char	*tmp;

	if (!buffer)
		buffer = my_calloc(sizeof(char), 1);
	if (!buffer)
		return (NULL);
	tmp = my_calloc((my_strlen(buffer) + size + 1), sizeof(char));
	if (!tmp)
		return (true_free(&buffer));
	i = -1;
	while (buffer[++i])
		tmp[i] = buffer[i];
	j = -1;
	while (tail[++j])
		tmp[i++] = tail[j];
	true_free(&buffer);
	return (tmp);
}

void	*true_free(char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

void	*my_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(sizeof(char) * (count * size));
	if (!res)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}
