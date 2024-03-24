/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_composure_parsing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:05:11 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/24 17:06:03 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_composure(char **map)
{
	int	x;
	int	y;
	int	tab[3];

	y = 0;
	ft_fill_tab(tab);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				tab[0]++;
			if (map[y][x] == 'C')
				tab[1]++;
			if (map[y][x] == 'E')
				tab[2]++;
			x++;
		}
		y++;
	}
	if (tab[0] != 1 || tab[2] != 1 || tab[1] == 0)
		return (-1);
	return (0);
}

void	ft_find_player_pos(char **map, int *x, int *y)
{
	(*y) = 0;
	while (map[*y])
	{
		(*x) = 0;
		while (map[*y][*x] && map[*y][*x] != 'P')
		{
			(*x)++;
		}
		if (map[*y][*x] == 'P')
			return ;
		(*y)++;
	}
}

int	ft_check_map_end(char **map)
{
	int	x;
	int	y;
	int	tab[4];

	y = 0;
	ft_fill_tab(tab);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				tab[0]++;
			if (map[y][x] == 'E')
				tab[1]++;
			x++;
		}
		y++;
	}
	if (tab[0] != 0 || tab[1] != 0)
		return (-1);
	return (0);
}

int	*ft_fill_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
