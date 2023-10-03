/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:00:30 by ohortal-          #+#    #+#             */
/*   Updated: 2023/01/16 15:27:34 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*rstr;

	i = 0;
	while (str[i])
		i++;
	rstr = (char *)str;
	while (i >= 0)
	{
		if (rstr[i] == (char)c)
			return (&rstr[i]);
		i--;
	}
	return (0);
}
