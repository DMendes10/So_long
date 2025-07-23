/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complementary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:17:15 by diomende          #+#    #+#             */
/*   Updated: 2025/07/23 18:30:51 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_orientation_sprite(char key, t_data *data, int x, int y)
{
	if (key == 'w')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.player_up, x * 64, y * 64);
	else if (key == 's')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.player, x * 64, y * 64);
	else if (key == 'a')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.player_left, x * 64, y * 64);
	else if (key == 'd')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.player_right, x * 64, y * 64);
}

int	elements_check_2(t_data *data)
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
			if (data->map[x][y] != 'P' && data->map[x][y] != '1' && data->map[x]
				[y] != '0' && data->map[x][y] != 'E' && data->map[x][y] != 'C')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	print_pokemon(char c, t_data *data, int x, int y)
{
	if (c == '2')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.collectable1, x * 64, y * 64);
	if (c == '3')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.collectable2, x * 64, y * 64);
	if (c == '4')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.collectable3, x * 64, y * 64);
	if (c == '5')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.collectable4, x * 64, y * 64);
	if (c == '6')
		mlx_put_image_to_window(data->game.mlx, data->game.win,
			data->sprites.collectable5, x * 64, y * 64);
}

int	new_line_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == '\n')
		i++;
	while (s[i])
	{
		if (s[i] == '\n')
			if (s[i + 1] == '\n')
				break ;
		i++;
	}
	while (s[i] == '\n')
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

void	modify_collectables(t_data *data)
{
	int		x;
	int		y;
	char	i;

	x = 0;
	y = 0;
	i = '2';
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'C')
			{
				data->map[x][y] = i;
				if (i > '5')
					i = '2';
				else
					i++;
			}
			y++;
		}
		x++;
	}
}
