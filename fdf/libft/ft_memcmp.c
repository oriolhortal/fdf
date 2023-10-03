/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:07:59 by ohortal-          #+#    #+#             */
/*   Updated: 2023/01/30 11:22:45 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				dif;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	dif = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		dif = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (dif != 0)
			return (dif);
		i++;
	}
	return (0);
}
