/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:27:31 by ohortal-          #+#    #+#             */
/*   Updated: 2023/01/19 13:59:17 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	i = 0;
	b = str;
	while (i < n)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
