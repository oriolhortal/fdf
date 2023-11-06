/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:00:51 by ohortal-          #+#    #+#             */
/*   Updated: 2023/11/05 13:03:46 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		win_x;
	int		win_y;
	int		bpp;
	int		endian;
	int		l_len;
	float	zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		**map;
	float	factor;
	float	angle;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		vista;
}		t_fdf;

typedef struct s_point
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}		t_point;

int		fill_data(char *file, t_fdf *data);
void	fill_map(t_fdf *data, int i, char *line);
int		fill_attr_data(int fd, t_fdf *data);
int		read_file(char *file, t_fdf *data);
void	isometric(float *x, float *y, float angle, int z);
void	put_pixel(t_point *p, t_fdf *data);
int		bresenham(t_point *p, t_fdf *data);
void	set_p(int x, int y, t_point *p, t_fdf *data);
int		draw(t_fdf *data);
int		max1(float a, float b);
int		mod1(float a);
int		ft_err(char *msg);
void	map_free(int i, t_fdf *data);
int		close_window(t_fdf *data);
int		deal_key(int key, t_fdf *data);
void	key_control(int key, t_fdf	*data);
int		deal_key(int key, t_fdf *data);
int		mouse_press(int button, int x, int y, t_fdf *data);
void	put_pixel_img(t_fdf *data, int x, int y);
int		drawing(t_fdf *data);
void	rotate(float *x, float *y, float angle);
int		file_fdf_check(char *file);
int		ft_count_word(char const *s, char c);

#endif
