/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:34:54 by diomende          #+#    #+#             */
/*   Updated: 2025/07/11 18:53:29 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map (int fd, t_data *data)
{
	char	*line_accumulator;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return_error (2);
	line_accumulator = ft_strdup("");
	while (line)
	{
		line_accumulator = ft_strjoin_gnl (line_accumulator, line);
		free (line);
		line = get_next_line(fd);
	}
	data->map = ft_split (line_accumulator, '\n');
	free (line_accumulator);
	free (line);
	map_checker (data);
}

void	map_checker(t_data *data)
{
	if (!shape_check (data))
		return_error (3);
	if (!wall_check (data))
		return_error (3);
	if (!elements_check (data, 0, 0, 0))
		return_error (4);
	if (!valid_path_check (data))
		return_error (5);
}


