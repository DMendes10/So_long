/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:37:49 by diomende          #+#    #+#             */
/*   Updated: 2025/07/11 20:21:10 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shape_check(t_data *data)
{
	size_t len;
	int i;

	i = 1;
	len = ft_strlen (data->map[0]);
	while (data->map[i])
	{
		if (strlen (data->map[i]) != len)
			return (0);
		i++;
	}
	if (!data->map[2])
		return (0);
	else
		return (1);
}

int	wall_check (t_data *data)
{
	size_t len;
	int i;

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

int	elements_check (t_data *data, int coin, int exit, int player)
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
	else
		return (1);
}

int	valid_path_check(t_data *data)
{
	int x;
	// int y;

	x = 0;
	if (!cpy_map (data))
		return_error (5, data);
	while (data->mapchecker[x])
	{
		printf ("%s\n", data->mapchecker[x]);
		x++;
	}
	return (1);
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
		data->mapchecker[y] = malloc (sizeof (char) * (ft_strlen (data->map[0]) + 1)); // preciso de alocar mais um * no meu array e meter a null??
		if (!data->mapchecker[y++])
			return (0);
	}
	x = 0;
	while (data->map[x])
	{
		ft_strlcpy (data->mapchecker[x], data->map[x], (ft_strlen (data->map[x]) + 1)); // preciso de alocar mais um * no meu array e meter a null??
		x++;
	}
	data->mapchecker[x] = NULL;
	return (1);
}