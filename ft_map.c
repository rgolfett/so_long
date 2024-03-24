/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:48:22 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/24 16:09:36 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_valid_file(char *file)
{
	int		i;
	int		fd;
	char	*ber;

	i = 0;
	ber = ".ber";
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(1, "Invalid file\n", 14), -1);
	close(fd);
	while (file[i])
		i++;
	if (i < 4)
	{
		write(1, "Invalid file\n", 14);
		return (-1);
	}
	i -= 4;
	if (ft_memcmp(&file[i], ber, 4) != 0)
	{
		write(1, "Invalid file\n", 14);
		return (-1);
	}
	return (close(fd), 0);
}

void	ft_display_map(t_vars vars)
{
	ft_draw_walls(vars);
	ft_draw_collectibles(vars);
	ft_draw_floor(vars);
	ft_draw_exit(vars);
	ft_draw_texture(vars.img, vars.player, vars.player_tex);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.floor.img, 100, 50);
}

int	ft_find_player(t_vars vars, int *x, int *y)
{
	char	**map;

	*y = 0;
	*x = 0;
	map = vars.map.map;
	while (map[*y])
	{
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return (0);
			(*x)++;
		}
		(*y)++;
		(*x) = 0;
	}
	return (-1);
}

char	**ft_fill_cpy_map(char **map, char **map_cpy)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map_cpy[y][x] = map[y][x];
			x++;
		}
		map_cpy[y][x] = '\0';
		y++;
	}
	map_cpy[y] = NULL;
	return (map_cpy);
}

char	**ft_create_cpy_map(char **map)
{
	int		x;
	int		y;
	char	**map_cpy;

	y = 0;
	x = 0;
	while (map[y][x])
		x++;
	while (map[y])
		y++;
	map_cpy = malloc(sizeof(char *) * (y + 1));
	if (!map_cpy)
		return (NULL);
	map_cpy[y] = NULL;
	while (y > 0)
	{
		y--;
		map_cpy[y] = malloc(sizeof(char) * (x + 1));
		if (!map_cpy[y])
			return (ft_reverse_free(map_cpy, (y)), NULL);
	}
	ft_fill_cpy_map(map, map_cpy);
	return (map_cpy);
}
