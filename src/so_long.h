/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:15:58 by diomende          #+#    #+#             */
/*   Updated: 2025/07/21 18:59:43 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/Libft/libft.h"
# include "../Minilibx/mlx.h"
# include "../Minilibx/mlx_int.h"
# include "../src/ft_printf/ft_printf.h"
// # include <X11/X.h>
// # include <X11/keysym.h>

typedef struct s_game
{
	int		exit_open;
	int		moves;
	int		pk_collected;
	void	*img;
	void	*mlx;
	void	*win;
}t_game;

typedef struct s_sprites
{
	void		*collectable;
	void		*exit;
	void		*wall;
	void		*floor;
	void		*player;
}t_sprites;

typedef struct s_data
{
	char		**map;
	char		**mapchecker;
	int			total_pk;
	int			x_player;
	int			y_player;
	int			map_width;
	int			map_height;
	t_game		game;
	t_sprites	sprites;
}t_data;

void	return_error (int error_code, t_data **data);
void	read_map (int fd, t_data *data);
void	free_array(char **s);
void	map_checker(t_data *data);
int		shape_check(t_data *data);
int		wall_check (t_data *data);
int		elements_check (t_data *data, int coin, int exit, int player);
int		valid_path_check(t_data *data);
int		cpy_map(t_data *data);
void	player_position (t_data *data);
void	flood_fill (t_data *data, int y, int x);
void	initialize_game (t_data *data);
void	initialize_images (t_data *data);
void	draw_map (t_data *data);
void	draw_map2 (t_data *data);
int		parse_inputs (int key, void *param);
void	move_player (t_data *data, int x, int y);
void	new_position(t_data *data, int new_x, int new_y);
void	free_maps(t_data **data);
void	free_all(t_data *data);
int		close_game(t_data *data);



#endif