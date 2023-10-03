/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:39:03 by ohortal-          #+#    #+#             */
/*   Updated: 2023/02/23 12:03:58 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_substrings(char const *s, char c)
{
	int	i;
	int	substrs;

	i = 0;
	substrs = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			substrs++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (substrs);
}

static int	ft_size_substring(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_str_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		substrs;
	char	**strs;
	int		j;

	i = 0;
	j = -1;
	substrs = ft_count_substrings(s, c);
	strs = (char **)malloc((substrs + 1) * sizeof(char *));
	if (!(strs))
		return (NULL);
	while (++j < substrs)
	{
		while (s[i] == c)
			i++;
		strs[j] = ft_substr(s, i, ft_size_substring(s, c, i));
		if (!(strs[j]))
		{
			ft_str_free(strs, j);
			return (NULL);
		}
		i += ft_size_substring(s, c, i);
	}
	strs[j] = 0;
	return (strs);
}
