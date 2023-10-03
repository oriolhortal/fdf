/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:18:01 by ohortal-          #+#    #+#             */
/*   Updated: 2023/02/06 12:35:52 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((unsigned int)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, (char *)s + start, len + 1);
	return (subs);
}
