/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:14:27 by diomende          #+#    #+#             */
/*   Updated: 2025/07/11 17:56:48 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void return_error (int error_code)
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
		ft_putstr_fd("Error\nCode 4: Map with missing/incorrect elements \n", 2);
	exit (0);
}

int main (int ac, char **av)
{
	int	fd;
	t_data	data;

	if ((ac > 2 || ac == 1) || !ft_strnstr (av[1], ".ber", ft_strlen(av[1])))
		return_error (0);
	fd = open (av[1], O_RDONLY);
	if (fd < 0)
		return_error (1);
	read_map (fd, &data);
	ft_free (data.map);
}

void	ft_free(char **s)
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
