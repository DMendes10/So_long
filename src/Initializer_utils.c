/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initializer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:40:15 by diomende          #+#    #+#             */
/*   Updated: 2025/07/23 18:28:27 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_data *data)
{
	data->game.mlx = mlx_init();
	if (!data->game.mlx)
		return_error (6, &data);
	data->game.win = mlx_new_window (data->game.mlx, 64 * data
			->map_width, 64 * data->map_height, "so_long");
	if (!data->game.win)
	{
		mlx_destroy_display(data->game.mlx);
		return_error (6, &data);
	}
	initialize_images (data);
	draw_map (data, 's');
}

void	initialize_images(t_data *data)
{
	int	width;
	int	height;

	data->sprites.floor = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/floor.xpm", &width, &height);
	data->sprites.player = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/P_down.xpm", &width, &height);
	data->sprites.player_up = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/P_up.xpm", &width, &height);
	data->sprites.player_right = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/P_right.xpm", &width, &height);
	data->sprites.player_left = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/P_left.xpm", &width, &height);
	data->sprites.wall = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/wall.xpm", &width, &height);
	data->sprites.collectable1 = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/trapinch.xpm", &width, &height);
	data->sprites.exit = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/exit_open.xpm", &width, &height);
	data->sprites.exit_closed = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/exit_closed.xpm", &width, &height);
	if (initialize_images_2 (data) == 0)
		return_error (7, &data);
}

int	initialize_images_2(t_data *data)
{
	int	width;
	int	height;

	data->sprites.collectable2 = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/cacnea.xpm", &width, &height);
	data->sprites.collectable3 = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/baltoy.xpm", &width, &height);
	data->sprites.collectable4 = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/sandshrew.xpm", &width, &height);
	data->sprites.collectable5 = mlx_xpm_file_to_image (
			data->game.mlx, "src/Sprites/regirock.xpm", &width, &height);
	if (!data->sprites.floor || !data->sprites.player || !data
		->sprites.wall || !data->sprites.collectable1 || !data
		->sprites.exit || !data->sprites.player_up || !data
		->sprites.player_right || !data->sprites.player_left || !data
		->sprites.collectable2 || !data->sprites.collectable3 || !data
		->sprites.collectable4 || !data->sprites.collectable5)
		return (0);
	return (1);
}

void	draw_map(t_data *data, char key)
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
			if (data->map[y][x] == '2' || data->map[y][x] == '3' || data->
				map[y][x] == '4' || data->map[y][x] == '5' || data
				->map[y][x] == '6')
				print_pokemon (data->map[y][x], data, x, y);
			x++;
		}
		y++;
	}
	draw_map2(data, key);
}

void	draw_map2(t_data *data, char key)
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
				player_orientation_sprite (key, data, x, y);
			if (data->map[y][x] == 'E' && data->game.exit_open == 1)
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					data->sprites.exit, x * 64, y * 64);
			if (data->map[y][x] == 'E' && data->game.exit_open == 0)
				mlx_put_image_to_window(data->game.mlx, data->game.win,
					data->sprites.exit_closed, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
