/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:22:16 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/15 17:57:10 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "get_next_line.h"

void	ft_clear_image(t_img img)
{
	ft_memset(img.data_addr, 0, sizeof(unsigned int) * (img.height * img.width));
}

void ft_draw_object(t_img img, t_object object, unsigned int color)
{
	int tmp;
	int width_sq = 50 + object.x;
	int height_sq = 50 + object.y;
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

t_img	load_img(void *mlx, t_img img, char *texture)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	img.img = mlx_xpm_file_to_image(mlx, texture, &img.width, &img.height);
	img.data_addr = mlx_get_data_addr(img.img, &bits_per_pixel, &size_line, &endian);
	return (img);
}

t_img	create_img(void *mlx, t_img img, int width, int height)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	img.img = mlx_new_image(mlx, width, height);
	img.data_addr = mlx_get_data_addr(img.img, &bits_per_pixel, &size_line, &endian);
	img.width = width;
	img.height = height;
	return (img);

}
void	ft_check_exit_condition(t_vars vars)
{
	char **map;
	int x;
	int	y;
	int collectibles;

	x = 0;
	y = 0;
	collectibles = 0;
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

void	ft_check_collectible_pos(t_vars vars)
{
	char **map;

	map = vars.map.map;
	if (map[vars.player.y / 50][vars.player.x / 50] == 'C')
		map[vars.player.y / 50][vars.player.x / 50] = '0';

}

int	ft_check_player_pos(t_vars vars)
{
	char **map;

	map = vars.map.map;
	if (map[vars.player.y / 50][vars.player.x / 50] == '1')
		return (-1);
	return (0);
}

void	on_key_press(int key, void *param)
{
	t_vars *vars;

	vars = ((t_vars *)param);
	if (key == KEY_W)
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
	if (key == KEY_A)
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
	if (key == KEY_S)
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
	
	if (key == KEY_D)
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
	if (key == KEY_ESC)
	{
		mlx_loop_end(vars->mlx);
	}
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
	
	vars.movement = 0;
	vars.player.x = 0;
	vars.player.y = 0;
 	vars.mlx = mlx_init();
	if (vars.mlx == (void*)0)
		return (-1);
	vars.map.map = ft_create_map(argv[1], &vars.map.w, &vars.map.h);
	ft_check_map(vars.map.map);
	vars.win = mlx_new_window(vars.mlx, (vars.map.w * 50), (vars.map.h * 50), "so_long");
	vars.img = create_img(vars.mlx, vars.img, (vars.map.w * 50), (vars.map.h * 50));
	vars.floor = load_img(vars.mlx, vars.floor, "touch-grass.xpm");
	vars.wall = load_img(vars.mlx, vars.wall, "bush.xpm");
	vars.collectible = load_img(vars.mlx, vars.collectible, "pomegrenade.xpm");
	vars.player_tex = load_img(vars.mlx, vars.player_tex, "baby_gryff.xpm");
	vars.exit = load_img(vars.mlx, vars.exit, "exit.xpm");
	ft_find_player(vars, &vars.player.x, &vars.player.y);
	vars.map.map[vars.player.y][vars.player.x] = '0';
	vars.player.x *= 50;
	vars.player.y *= 50;
	ft_display_map(vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, (void *)on_key_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
