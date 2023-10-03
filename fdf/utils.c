/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:43 by ohortal-          #+#    #+#             */
/*   Updated: 2023/10/03 10:54:18 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	max1(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	mod1(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	return (-1);
}

void	map_free(int i, t_fdf *data)
{
	while (i > 0)
		free(data->map[i--]);
	free(data->map);
	free(data);
}

int	close_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}
