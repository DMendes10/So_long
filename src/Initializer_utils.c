/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initializer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:15 by diomende          #+#    #+#             */
/*   Updated: 2025/07/21 19:26:37 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game (t_data *data)
{
	data->game.mlx = mlx_init();
	if (!data->game.mlx)
		return_error (6, &data);
	data->game.win = mlx_new_window (data->game.mlx, 64 * data->map_width, 64 * data->map_height, "so_long");
	if (!data->game.win)
	{
		mlx_destroy_display(data->game.mlx);
		return_error (6, &data);
	}
	initialize_images (data);
	draw_map (data);
}

void	initialize_images (t_data *data)
{
	int	width;
	int	height;

	data->sprites.floor = mlx_xpm_file_to_image (data->game.mlx, "src/Sprites/floor.xpm", &width, &height);
	data->sprites.player = mlx_xpm_file_to_image (data->game.mlx, "src/Sprites/P_down.xpm", &width, &height);
	data->sprites.wall = mlx_xpm_file_to_image (data->game.mlx, "src/Sprites/wall.xpm", &width, &height);
	data->sprites.collectable = mlx_xpm_file_to_image (data->game.mlx, "src/Sprites/trapinch.xpm", &width, &height);
	data->sprites.exit = mlx_xpm_file_to_image (data->game.mlx, "src/Sprites/exit_open.xpm", &width, &height);
	if (!data->sprites.floor || !data->sprites.player || !data->sprites.wall || !data->sprites.collectable 
		|| !data->sprites.exit)
		return_error (7, &data);
}

void	draw_map (t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					 data->sprites.wall, x * 64, y * 64);
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					 data->sprites.floor, x * 64, y * 64);
			if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					 data->sprites.collectable, x * 64, y * 64);
			x++;
		}
		y++;
	}
	draw_map2(data);
}

void	draw_map2 (t_data *data)
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
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					 data->sprites.player, x * 64, y * 64);
			if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					 data->sprites.exit, x * 64, y * 64);
			// if (data->map[y][x] == 'C')
			// 	mlx_put_image_to_window(data->game->mlx, data->game->win,
			// 		 data->sprites->, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
