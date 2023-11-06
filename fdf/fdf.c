/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:02:29 by ohortal-          #+#    #+#             */
/*   Updated: 2023/11/05 13:02:46 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(float *x, float *y, float angle)
{
	*x = (*x * cos(angle)) + (*y * sin(angle));
	*y = (-1 * (*x * sin(angle))) + (*y * cos(angle));
}

int	ft_fdf_exten(char *file)
{
	char	**exten;
	int		i;
	int		cmp;

	exten = ft_split(file, '.');
	i = 0;
	cmp = 0;
	if (exten && exten[1])
		cmp = ft_strncmp(exten[1], "fdf", 3);
	while (exten[i])
	{
		free(exten[i]);
		i++;
	}
	free(exten);
	return (cmp);
}

int	file_fdf_check(char *file)
{
	char	*line;
	int		width;
	int		fd;

	if (ft_fdf_exten(file))
		return (1);
	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		return (ft_err("Can't open file"));
	line = get_next_line(fd);
	width = ft_count_word(line, ' ');
	while (line)
	{
		if (width != ft_count_word(line, ' '))
		{
			free(line);
			close(fd);
			return (ft_err("Not all rows have the same number of elements\n"));
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (1);
	if (file_fdf_check(argv[1]))
		return (1);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (ft_err("Error: malloc error"));
	if (read_file(argv[1], data) < 0)
	{
		free(data);
		return (1);
	}
	drawing(data);
	free(data);
	return (0);
}
