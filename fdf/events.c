/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:19 by ohortal-          #+#    #+#             */
/*   Updated: 2023/11/05 13:07:58 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	key_control(int key, t_fdf *data)
{
	if (key == 53)
		close_window(data);
	if (key == 126)
		data->shift_y -= 5;
	if (key == 125)
		data->shift_y += 5;
	if (key == 123)
		data->shift_x -= 5;
	if (key == 124)
		data->shift_x += 5;
	if (key == 69)
		data->zoom += 0.5;
	if (key == 78)
		data->zoom -= 0.5;
	if (key == 0)
		data->angle += 0.01;
	if (key == 1)
		data->angle -= 0.01;
	if (key == 14)
		data->factor += 0.2;
	if (key == 2)
		data->factor -= 0.2;
}

int	deal_key(int key, t_fdf *data)
{
	key_control(key, data);
	if (key == 35)
	{
		data->vista = 0;
		data->angle = 0;
		data->shift_x = 20;
		data->shift_y = 20;
	}
	if (key == 31)
	{
		data->vista = 1;
		data->angle = 0.8;
		data->shift_x = 1000 - (data->width / 2);
		data->shift_y = 500 - (data->height / 2);
	}
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
		data->zoom += 0.5;
	if (button == 5)
		data->zoom -= 0.5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void	put_pixel_img(t_fdf *data, int x, int y)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < data->win_x && y < data->win_y)
	{
		dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
		*(unsigned int *)dst = data->color;
	}
}

int	drawing(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
			data->win_x, data->win_y, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_mouse_hook(data->win_ptr, mouse_press, data);
	mlx_loop(data->mlx_ptr);
	map_free(data->width, data);
	return (0);
}
