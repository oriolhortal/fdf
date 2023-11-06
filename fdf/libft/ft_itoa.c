/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:38:44 by ohortal-          #+#    #+#             */
/*   Updated: 2023/02/07 14:38:49 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	digits(int n)
{
	int			i;
	long int	nb;

	i = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -1 * nb;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	nb = n;
	len = digits(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str)
	{
		str[len--] = '\0';
		if (nb == 0)
			str[0] = '0';
		if (nb < 0)
		{
			str[0] = '-';
			nb = -1 * nb;
		}
		while (nb != 0)
		{
			str[len--] = (nb % 10) + 48;
			nb /= 10;
		}
	}
	return (str);
}
