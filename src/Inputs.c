/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:36:32 by diomende          #+#    #+#             */
/*   Updated: 2025/07/21 18:58:22 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_inputs (int key, void *param)
{
	t_data *data;

	data = (t_data *)param;
	// if (key == XK_Escape)
		// close_game(data);
	if (key == XK_w)
		move_player(data, 0, -1);
	if (key == XK_s)
		move_player(data, 0, 1);
	if (key == XK_a)
		move_player(data, -1, 0);
	if (key == XK_d)
		move_player(data, 1, 0);
	return (1);
}

void	move_player (t_data *data, int x, int y)
{
	int		new_x;
	int		new_y;
	char	new_cordinates;

	new_x = data->x_player + x;
	new_y = data->y_player + y;
	new_cordinates = data->map[new_y][new_x];
	if (new_cordinates == '1' || (new_cordinates == 'E' && data->game.exit_open == 0))
		return ;
	data->game.moves++;
	new_position(data, new_x, new_y);
	ft_printf("Moves: %d\n", data->game.moves);
	if (new_cordinates == 'C')
	{
		data->game.pk_collected++;
		if (data->game.pk_collected == data->total_pk)
			data->game.exit_open = 1;
		draw_map (data);
	}
	if (new_cordinates == 'E' && data->game.exit_open == 1)
	{
		ft_printf ("You Catched'Em All!!!!");
		close_game (data);
	}
}

void	new_position(t_data *data, int new_x, int new_y)
{
	// if (data->map[data->y_player + new_y][data->x_player + new_x] == '1' ||
	// 	 (data->map[data->y_player + new_y][data->x_player + new_x] == 'E' && data->game.exit_open == 0))
	// 	return ;
	// else
	// {
	// if (data->map[data->y_player][data->x_player] == 'E')
	data->map[data->y_player][data->x_player] = '0';
	data->x_player = new_x;
	data->y_player = new_y;
	data->map[new_y][new_x] = 'P';
	draw_map(data);
	// }
}

int	close_game(t_data *data)
{
	free_all (data);
	exit(0);
	return (0);
}
