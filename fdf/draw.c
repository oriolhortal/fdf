/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:07 by ohortal-          #+#    #+#             */
/*   Updated: 2023/11/05 13:08:13 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	isometric(float *x, float *y, float angle, int z)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	put_pixel(t_point *p, t_fdf *data)
{
	int		max;
	float	x_step;
	float	y_step;

	p->x *= data->zoom;
	p->y *= data->zoom;
	p->x1 *= data->zoom;
	p->y1 *= data->zoom;
	p->x += data->shift_x;
	p->y += data->shift_y;
	p->x1 += data->shift_x;
	p->y1 += data->shift_y;
	x_step = (p->x1 - p->x);
	y_step = p->y1 - p->y;
	max = max1(mod1(x_step), mod1(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p->x - p->x1) || (int)(p->y - p->y1))
	{
		put_pixel_img(data, p->x, p->y);
		p->x += x_step;
		p->y += y_step;
	}
}

int	bresenham(t_point *p, t_fdf *data)
{
	int	z;
	int	z1;

	z = data->map[(int)(p->y)][(int)(p->x)] * data->factor;
	z1 = data->map[(int)(p->y1)][(int)(p->x1)] * data->factor;
	data->color = 0xFFFFFF;
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c + ((z1 - z) / 256);
	else if (z < 0 || z1 < 0)
		data->color = 0x0000FF - ((z1 - z) / 256);
	if (data->vista)
	{
		isometric(&(p->x), &(p->y), data->angle, z);
		isometric(&(p->x1), &(p->y1), data->angle, z1);
	}
	else
	{
		rotate(&(p->x), &(p->y), data->angle);
		rotate(&(p->x1), &(p->y1), data->angle);
	}
	put_pixel(p, data);
	return (1);
}

void	set_p(int x, int y, t_point *p, t_fdf *data)
{
	if (x < data->width - 1)
	{
		p->x = x;
		p->y = y;
		p->x1 = x + 1;
		p->y1 = y;
		bresenham(p, data);
	}
	if (y < data->height - 1)
	{
		p->x = x;
		p->y = y;
		p->x1 = x;
		p->y1 = y + 1;
		bresenham(p, data);
	}
}

int	draw(t_fdf *data)
{
	int		x;
	int		y;
	t_point	*p;

	data->img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->addr = mlx_get_data_addr(data->img, \
			&(data->bpp), &(data->l_len), &(data->endian));
	p = (t_point *)malloc(sizeof(t_point));
	if (!p)
		return (ft_err("Can't make the point"));
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			set_p(x, y, p, data);
			x++;
		}
		y++;
	}
	free(p);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (1);
}
