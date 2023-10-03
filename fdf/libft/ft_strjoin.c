/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:36:26 by ohortal-          #+#    #+#             */
/*   Updated: 2023/02/06 15:09:33 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	int			i;
	int			a;
	int			len;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	a = ft_strlen(s2);
	len = i + a;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(&new[0], (char *)s1, i + 1);
	ft_strlcpy(&new[i], (char *)s2, a + 1);
	return (new);
}
