/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:58:01 by diomende          #+#    #+#             */
/*   Updated: 2025/07/23 17:08:15 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	free_all(t_data *data)
{
	free_collectables (data);
	free_player (data);
	if (data->sprites.exit)
		mlx_destroy_image(data->game.mlx, data->sprites.exit);
	if (data->sprites.floor)
		mlx_destroy_image(data->game.mlx, data->sprites.floor);
	if (data->sprites.wall)
		mlx_destroy_image(data->game.mlx, data->sprites.wall);
	if (data->sprites.exit_closed)
		mlx_destroy_image(data->game.mlx, data->sprites.exit_closed);
	if (data->game.win)
		mlx_destroy_window(data->game.mlx, data->game.win);
	if (data->game.mlx)
	{
		mlx_destroy_display(data->game.mlx);
		free (data->game.mlx);
	}
	free_maps (&data);
}

void	free_maps(t_data **data)
{
	if ((*data)->map)
		free_array ((*data)->map);
	if ((*data)->mapchecker)
		free_array ((*data)->mapchecker);
	free (*data);
}

void	free_collectables(t_data *data)
{
	if (data->sprites.collectable1)
		mlx_destroy_image(data->game.mlx, data->sprites.collectable1);
	if (data->sprites.collectable2)
		mlx_destroy_image(data->game.mlx, data->sprites.collectable2);
	if (data->sprites.collectable3)
		mlx_destroy_image(data->game.mlx, data->sprites.collectable3);
	if (data->sprites.collectable4)
		mlx_destroy_image(data->game.mlx, data->sprites.collectable4);
	if (data->sprites.collectable5)
		mlx_destroy_image(data->game.mlx, data->sprites.collectable5);
}

void	free_player(t_data *data)
{
	if (data->sprites.player)
		mlx_destroy_image(data->game.mlx, data->sprites.player);
	if (data->sprites.player_up)
		mlx_destroy_image(data->game.mlx, data->sprites.player_up);
	if (data->sprites.player_right)
		mlx_destroy_image(data->game.mlx, data->sprites.player_right);
	if (data->sprites.player_left)
		mlx_destroy_image(data->game.mlx, data->sprites.player_left);
}
