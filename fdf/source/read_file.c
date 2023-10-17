/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:34 by ohortal-          #+#    #+#             */
/*   Updated: 2023/10/03 11:35:56 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	ft_count_word(char const *s, char c)
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
		return (ft_error("Can't open file"));
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
	data->map = (int **)malloc(sizeof(int *) * data->height + 1);
	if (!data->map)
		return (ft_error("Cna't fill row"));
	data->map[data->height] = NULL;
	return (0);
}

void	fill_map(int *map, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		map[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	fill_attr_data(int fd, t_fdf *data)
{
	char	*line;
	int		i;

	data->zoom = 20;
	data->shift_x = 350;
	data->shift_y = 350;
	data->angle = 0.56;
	data->factor = 1;
	i = 0;
	line = get_next_line(fd);
	while (data->map[i])
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->map[i])
		{
			map_free(i, data);
			return (ft_error("Can't malloc"));
		}
		fill_map(data->map[i++], line);
		free(line);
		line = get_next_line(fd);
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
		return (ft_error("Can't open file"));
	fill_attr_data(fd, data);
	close(fd);
	return (1);
}
