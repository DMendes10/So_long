/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:34:54 by diomende          #+#    #+#             */
/*   Updated: 2025/07/22 19:30:30 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_data *data)
{
	char	*line_accumulator;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return_error (2, &data);
	line_accumulator = ft_strdup("");
	while (line)
	{
		line_accumulator = ft_strjoin_gnl (line_accumulator, line);
		free (line);
		line = get_next_line(fd);
	}
	if (!new_line_check (line_accumulator))
	{
		free (line);
		free (line_accumulator);
		return_error (3, &data);
	}
	data->map = ft_split (line_accumulator, '\n');
	free (line_accumulator);
	free (line);
	map_checker (data);
}

void	map_checker(t_data *data)
{
	if (!shape_check (data))
		return_error (3, &data);
	if (!wall_check (data))
		return_error (3, &data);
	if (!elements_check (data, 0, 0, 0))
		return_error (4, &data);
	if (!valid_path_check (data))
		return_error (5, &data);
}

int	cpy_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x])
		x++;
	data->mapchecker = malloc (sizeof (char *) * (x + 1));
	if (!data->mapchecker)
		return (0);
	while (y < x)
	{
		data->mapchecker[y] = malloc (sizeof (char) * (ft_strlen
					(data->map[0]) + 1));
		if (!data->mapchecker[y++])
			return (0);
	}
	x = 0;
	while (data->map[x])
	{
		ft_strlcpy (data->mapchecker[x], data->map[x], (ft_strlen
				(data->map[x]) + 1));
		x++;
	}
	return (data->mapchecker[x] = NULL, 1);
}

void	player_position(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->y_player = y;
				data->x_player = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	exit_cordinates(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				data->y_exit = y;
				data->x_exit = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
