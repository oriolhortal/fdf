/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:34 by ohortal-          #+#    #+#             */
/*   Updated: 2023/11/05 13:09:45 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

int	fill_data(char *file, t_fdf *data)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		return (ft_err("Can't open file"));
	line = get_next_line(fd);
	data->width = ft_count_word(line, ' ');
	data->height = 0;
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	data->map = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->map)
		return (ft_err("Can't fill row"));
	data->map[data->height] = NULL;
	return (0);
}

void	fill_map(t_fdf *data, int i, char *line)
{
	char	**nums;
	int		j;

	nums = ft_split(line, ' ');
	j = 0;
	while (j < data->width)
	{
		data->map[i][j] = ft_atoi(nums[j]);
		free(nums[j]);
		j++;
	}
	free(nums);
}

int	fill_attr_data(int fd, t_fdf *data)
{
	char	*line;
	int		i;

	if (data->width < 50 || data->height < 50)
		data->zoom = 20;
	else
		data->zoom = 5;
	i = 0;
	line = get_next_line(fd);
	while (i < data->height)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->width);
		if (!(data->map[i]))
		{
			map_free(i, data);
			return (ft_err("Can't malloc"));
		}
		fill_map(data, i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (1);
}

int	read_file(char *file, t_fdf *data)
{
	int	fd;

	if (fill_data(file, data) < 0)
		return (-1);
	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		return (ft_err("Can't open file"));
	fill_attr_data(fd, data);
	data->shift_x = 1000 - (data->width / 2);
	data->shift_y = 500 - (data->height / 2);
	data->angle = 0.8;
	data->factor = 1;
	close(fd);
	data->win_x = 2000;
	data->win_y = 1000;
	data->vista = 1;
	return (1);
}
