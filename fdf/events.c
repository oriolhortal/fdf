/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:19 by ohortal-          #+#    #+#             */
/*   Updated: 2023/10/03 10:51:59 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	key_control(int key, t_fdf *data)
{
	if (key == 53)
		close_window(data);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 69)
		data->zoom += 10;
	if (key == 78)
		data->zoom -= 10;
	if (key == 0)
		data->angle += 0.01;
	if (key == 1)
		data->angle -= 0.01;
	if (key == 14)
		data->factor += 1;
	if (key == 2)
		data->factor -= 1;
}

int	deal_key(int key, t_fdf *data)
{
	key_control(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->angle += 0.01;
	if (button == 2)
		data->angle -= 0.01;
	if (button == 3)
		data->factor++;
	if (button == 4)
		data->zoom += 1;
	if (button == 5)
		data->zoom -= 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
