/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:33:25 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/24 16:44:59 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key_press(t_vars *vars)
{
	vars->player.y -= 50;
	if (ft_check_player_pos(*vars) == -1)
		vars->player.y += 50;
	else
	{
		vars->movement++;
		ft_putnbr_fd(vars->movement);
	}
}

void	a_key_press(t_vars *vars)
{
	vars->player.x -= 50;
	if (ft_check_player_pos(*vars) == -1)
		vars->player.x += 50;
	else
	{
		vars->movement++;
		ft_putnbr_fd(vars->movement);
	}
}

void	d_key_press(t_vars *vars)
{
	vars->player.x += 50;
	if (ft_check_player_pos(*vars) == -1)
		vars->player.x -= 50;
	else
	{
		vars->movement++;
		ft_putnbr_fd(vars->movement);
	}
}

void	s_key_press(t_vars *vars)
{
	vars->player.y += 50;
	if (ft_check_player_pos(*vars) == -1)
		vars->player.y -= 50;
	else
	{
		vars->movement++;
		ft_putnbr_fd(vars->movement);
	}
}

void	ft_key_press(t_vars *vars, int key)
{
	if (key == KEY_W)
		w_key_press(vars);
	if (key == KEY_A)
		a_key_press(vars);
	if (key == KEY_S)
		s_key_press(vars);
	if (key == KEY_D)
		d_key_press(vars);
	if (key == KEY_ESC)
		mlx_loop_end(vars->mlx);
}
