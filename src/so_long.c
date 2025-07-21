/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:14:27 by diomende          #+#    #+#             */
/*   Updated: 2025/07/21 19:34:37 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void return_error (int error_code, t_data **data)
{
	if (error_code == 0)
		ft_putstr_fd("Error\nCode 0: No valid map file was provided \n", 2);
	else if (error_code == 1)
		ft_putstr_fd("Error\nCode 1: Unable to open file\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Error\nCode 2: Empty map file \n", 2);
	else if (error_code == 3)
		ft_putstr_fd("Error\nCode 3: Map with invalid shape/border \n", 2);
	else if (error_code == 4)
		ft_putstr_fd("Error\nCode 4: Map with missing/invalid elements \n", 2);
	else if (error_code == 5)
		ft_putstr_fd("Error\nCode 5: Map with no valid path \n", 2);
	else if (error_code == 6)
		ft_putstr_fd("Error\nCode 6: Window initialization problem \n", 2);
	else if (error_code == 7)
		ft_putstr_fd("Error\nCode 7: Image initialization problem \n", 2);
	if (data)
		free_all (*data);
	exit (0);
}

int main (int ac, char **av)
{
	int	fd;
	t_data	*data;

	if ((ac > 2 || ac == 1) || !ft_strnstr (av[1], ".ber", ft_strlen(av[1])))
		return_error (0, NULL);
	data = malloc (sizeof(t_data));
	data = ft_memset (data, 0, sizeof (t_data));
	fd = open (av[1], O_RDONLY);
	if (fd < 0)
		return_error (1, &data);
	read_map (fd, data);
	close (fd);
	initialize_game (data);
	mlx_hook (data->game.win, KeyPress, KeyPressMask, parse_inputs, data);
	mlx_loop (data->game.mlx);
}

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
	if (data->sprites.collectable)
		mlx_destroy_image(data->game.mlx, data->sprites.collectable);
	if (data->sprites.exit)
		mlx_destroy_image(data->game.mlx, data->sprites.exit);
	if (data->sprites.floor)
		mlx_destroy_image(data->game.mlx, data->sprites.floor);
	if (data->sprites.player)
		mlx_destroy_image(data->game.mlx, data->sprites.player);
	if (data->sprites.wall)
		mlx_destroy_image(data->game.mlx, data->sprites.wall);
	// if (data->sprites.exit_closed)
	// 	mlx_destroy_image(data->game.mlx, data->sprites.exit_closed);
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
