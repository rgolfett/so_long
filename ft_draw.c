/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:38:58 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/21 09:02:12 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw_walls(t_vars vars)
{
	char		**map;
	int			x;
	int			y;
	t_object	wall;

	y = 0;
	x = 0;
	map = vars.map.map;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				wall.x = x * 50;
				wall.y = y * 50;
				ft_draw_texture(vars.img, wall, vars.wall);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (y);
}

int	ft_draw_collectibles(t_vars vars)
{
	char		**map;
	int			x;
	int			y;
	t_object	collectible;

	y = 0;
	x = 0;
	map = vars.map.map;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				collectible.x = x * 50;
				collectible.y = y * 50;
				ft_draw_texture(vars.img, collectible, vars.collectible);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (-1);
}

int	ft_draw_exit(t_vars vars)
{
	char		**map;
	int			x;
	int			y;
	t_object	exit;

	y = 0;
	x = 0;
	map = vars.map.map;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				exit.x = x * 50;
				exit.y = y * 50;
				ft_draw_texture(vars.img, exit, vars.exit);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (-1);
}

void	ft_draw_texture(t_img img, t_object object, t_img texture)
{
	int	tmp;
	int	tmpy;
	int	width_sq;
	int	height_sq;

	width_sq = 50 + object.x;
	height_sq = 50 + object.y;
	tmpy = object.y;
	while (object.y < height_sq)
	{
		tmp = object.x;
		while (object.x < width_sq)
		{
			img.data_addr[object.y * img.width + object.x] = texture.data_addr
			[(object.y - tmpy) * texture.width + (object.x - tmp)];
			object.x++;
		}
		object.y++;
		object.x = tmp;
	}
}

int	ft_draw_floor(t_vars vars)
{
	char		**map;
	int			x;
	int			y;
	t_object	floor;

	y = 0;
	x = 0;
	map = vars.map.map;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				floor.x = x * 50;
				floor.y = y * 50;
				ft_draw_texture(vars.img, floor, vars.floor);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (-1);
}
