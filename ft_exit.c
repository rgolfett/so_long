/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:16:02 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/21 08:16:39 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit_condition(t_vars vars)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = vars.map.map;
	if (map[vars.player.y / 50][vars.player.x / 50] == 'E')
	{
		while (map[y])
		{
			while (map[y][x])
			{
				if (map[y][x] == 'C')
					return ;
				x++;
			}
			y++;
			x = 0;
		}
		mlx_loop_end(vars.mlx);
	}
}

int	ft_close(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
