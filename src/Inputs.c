/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:36:32 by diomende          #+#    #+#             */
/*   Updated: 2025/07/23 18:29:31 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_inputs(int key, t_data *data)
{
	if (key == XK_Escape)
		close_game(data);
	if (key == XK_w)
		move_player('w', data, 0, -1);
	if (key == XK_s)
		move_player('s', data, 0, 1);
	if (key == XK_a)
		move_player('a', data, -1, 0);
	if (key == XK_d)
		move_player('d', data, 1, 0);
	return (1);
}

void	move_player(char key, t_data *data, int x, int y)
{
	int		new_x;
	int		new_y;
	char	new_cordinates;

	new_x = data->x_player + x;
	new_y = data->y_player + y;
	new_cordinates = data->map[new_y][new_x];
	if (new_cordinates == '1')
		return ;
	data->game.moves++;
	new_position(key, data, new_x, new_y);
	if (new_cordinates == '2' || new_cordinates == '3' || new_cordinates == '4'
		|| new_cordinates == '5' || new_cordinates == '6')
		poke_tracker (data, new_cordinates, key);
	if (new_cordinates == 'E' && data->game.exit_open == 1)
	{
		ft_printf ("You Caught'Em All!!!!");
		close_game (data);
	}
}

void	new_position(char key, t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == 'E' && data->game.exit_open == 0)
	{
		data->map[data->y_player][data->x_player] = '0';
		data->x_player = new_x;
		data->y_player = new_y;
		data->map[new_y][new_x] = 'P';
		draw_map(data, key);
	}
	else
	{
		data->map[data->y_player][data->x_player] = '0';
		data->x_player = new_x;
		data->y_player = new_y;
		data->map[new_y][new_x] = 'P';
		data->map[data->y_exit][data->x_exit] = 'E';
		draw_map(data, key);
	}
	ft_printf("Moves: %d\n", data->game.moves);
}

int	close_game(t_data *data)
{
	free_all (data);
	exit(0);
	return (0);
}

void	poke_tracker(t_data *data, char cordinates, char key)
{
	data->game.pk_collected++;
	if (data->game.pk_collected == data->total_pk)
		data->game.exit_open = 1;
	if (cordinates != '6')
		ft_printf ("Gotcha!\n");
	else
		ft_printf ("UN UN UN UN UN UN UN UN UN UN UN UN UN UN\n");
	draw_map (data, key);
}
