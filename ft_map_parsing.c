/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:39:53 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/25 12:04:17 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_border(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y][x] != '\n')
	{
		if (map[y][x] != '1')
			return (-1);
		x++;
	}
	return (0);
}

int	ft_check_map_wall(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][0] != '1')
				return (-1);
			x++;
		}
		if (map[y][x - 1] != '1')
			return (-1);
		y++;
	}
	x = 0;
	while (map[y - 1][x] != '\n')
	{
		if (map[y - 1][x] != '1')
			return (-1);
		x++;
	}
	return (0);
}

void	ft_check_flood(char **map_cpy, int x, int y)
{
	map_cpy[y][x] = '1';
	if (map_cpy[y][x - 1] != '1')
		ft_check_flood(map_cpy, (x - 1), y);
	if (map_cpy[y][x + 1] != '1')
		ft_check_flood(map_cpy, (x + 1), y);
	if (map_cpy[y - 1][x] != '1')
		ft_check_flood(map_cpy, x, (y - 1));
	if (map_cpy[y + 1][x] != '1')
		ft_check_flood(map_cpy, x, (y + 1));
}

void	ft_check_path(char **map_cpy)
{
	int	y;
	int	x;

	ft_find_player_pos(map_cpy, &x, &y);
	ft_check_flood(map_cpy, x, y);
}

int	ft_check_map(char **map)
{
	char	**map_cpy;
	int		i;

	if (map == NULL)
		return (write(1, "Error\nInvalid file\n", 19), -1);
	i = 0;
	if (ft_check_border(map) == -1)
		return (write(1, "Error\nInvalid map\n", 18), -1);
	if (ft_check_map_composure(map) == -1 || ft_check_map_wall(map) == -1)
		return (write(1, "Error\nInvalid map\n", 18), -1);
	map_cpy = ft_create_cpy_map(map);
	if (map_cpy == NULL)
		return (-1);
	ft_check_path(map_cpy);
	while (map_cpy[i])
		i++;
	if (ft_check_map_end(map_cpy) == -1)
		return (write(1, "Error\nInvalid map\n", 18), ft_free(map_cpy, i), -1);
	ft_free (map_cpy, i);
	return (0);
}
