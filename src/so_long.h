/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:15:58 by diomende          #+#    #+#             */
/*   Updated: 2025/07/11 17:54:29 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/Libft/libft.h"
// # include "../lib/minilibx-linux/mlx.h"
// # include <X11/X.h>
// # include <X11/keysym.h>

typedef struct s_data
{
	char **map;
	char **mapchecker;
}t_data;

void return_error (int error_code);
void	read_map (int fd, t_data *data);
void	ft_free(char **s);
void	map_checker(t_data *data);
int	shape_check(t_data *data);
int	wall_check (t_data *data);
int	elements_check (t_data *data, int coin, int exit, int player);


#endif