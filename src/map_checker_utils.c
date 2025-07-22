/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:37:49 by diomende          #+#    #+#             */
/*   Updated: 2025/07/22 19:16:39 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shape_check(t_data *data)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen (data->map[0]);
	while (data->map[i])
	{
		if (ft_strlen (data->map[i]) != len)
			return (0);
		i++;
	}
	if (!data->map[2])
		return (0);
	else
	{
		data->map_height = i;
		data->map_width = len;
		return (1);
	}
}

int	wall_check(t_data *data)
{
	size_t	len;
	int		i;

	len = 0;
	i = 1;
	while (data->map[0][len])
		if (data->map[0][len++] != '1')
			return (0);
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][len - 1] != '1')
			return (0);
		i++;
	}
	len = 0;
	while (data->map[i - 1][len])
		if (data->map[i - 1][len++] != '1')
			return (0);
	return (1);
}

int	elements_check(t_data *data, int coin, int exit, int player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
				player++;
			else if (data->map[x][y] == 'E')
				exit++;
			else if (data->map[x][y] == 'C')
				coin++;
			y++;
		}
		x++;
	}
	if (player != 1 || exit != 1 || coin < 1)
		return (0);
	data->total_pk = coin;
	return (elements_check_2 (data));
}

int	valid_path_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!cpy_map (data))
		return_error (5, &data);
	player_position (data);
	flood_fill (data, data->y_player, data->x_player);
	while (data->mapchecker[y])
	{
		x = 0;
		while (data->mapchecker[y][x])
		{
			if (data->mapchecker[y][x] == 'E' || data->mapchecker[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill(t_data *data, int y, int x)
{
	if (data->mapchecker[y][x] == '1' || data->mapchecker[y][x] == 'D')
		return ;
	if (data->mapchecker[y][x] == '0' || data->mapchecker[y][x] == 'C' ||
	(data->mapchecker[y][x] == 'P' || data->mapchecker[y][x] == 'E'))
		data->mapchecker[y][x] = 'D';
	if (y > 0)
		flood_fill (data, y - 1, x);
	if (data->mapchecker[y + 1])
		flood_fill (data, y + 1, x);
	if (x > 0)
		flood_fill (data, y, x - 1);
	if (data->mapchecker[y][x + 1])
		flood_fill (data, y, x + 1);
}
