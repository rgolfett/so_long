/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:22:16 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/24 16:18:46 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	ft_draw_object(t_img img, t_object object, unsigned int color)
{
	int	tmp;
	int	width_sq;
	int	height_sq;

	width_sq = 50 + object.x;
	height_sq = 50 + object.y;
	while (object.y < height_sq)
	{
		tmp = object.x;
		while (object.x < width_sq)
		{
			img.data_addr[object.y * img.width + object.x] = color;
			object.x++;
		}
		object.y++;
		object.x = tmp;
	}
}

void	ft_check_collectible_pos(t_vars vars)
{
	char	**map;

	map = vars.map.map;
	if (map[vars.player.y / 50][vars.player.x / 50] == 'C')
		map[vars.player.y / 50][vars.player.x / 50] = '0';
}

int	ft_check_player_pos(t_vars vars)
{
	char	**map;

	map = vars.map.map;
	if (map[vars.player.y / 50][vars.player.x / 50] == '1')
		return (-1);
	return (0);
}

void	on_key_press(int key, void *param)
{
	t_vars	*vars;

	vars = ((t_vars *)param);
	ft_key_press(vars, key);
	ft_check_collectible_pos(*vars);
	ft_check_exit_condition(*vars);
	if (vars->player.y > (vars->map.h * 50) - 50)
		vars->player.y = (vars->map.h * 50) - 50;
	if (vars->player.y < 0)
		vars->player.y = 0;
	if (vars->player.x > (vars->map.w * 50) - 50)
		vars->player.x = (vars->map.w * 50) - 50;
	if (vars->player.x < 0)
		vars->player.x = 0;
	ft_clear_image(vars->img);
	ft_display_map(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (-1);
	vars = (t_vars){0};
	vars.mlx = mlx_init();
	if (vars.mlx == (void *)0 || ft_valid_file(argv[1]) == -1)
		return (-1);
	vars.map.map = ft_create_map(argv[1], &vars.map.w, &vars.map.h);
	if (ft_check_map(vars.map.map) == -1)
		return (ft_destroy_image(vars), -1);
	if (ft_load_sprites(&vars) == -1)
		return (ft_destroy_image(vars), -1);
	ft_find_player(vars, &vars.player.x, &vars.player.y);
	vars.map.map[vars.player.y][vars.player.x] = '0';
	vars.player.x *= 50;
	vars.player.y *= 50;
	ft_display_map(vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, (void *)on_key_press, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	ft_destroy_image(vars);
	return (0);
}
