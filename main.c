/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:22:16 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/13 12:31:52 by rgolfett         ###   ########lyon.fr   */
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

t_img	create_img(void *mlx, t_img img, int width, int height)
{
	void *window_img;
	unsigned int *data_addr;
	int bits_per_pixel;
	int size_line;
	int endian;

	img.img = mlx_new_image(mlx, width, height);
	img.data_addr = mlx_get_data_addr(img.img, &bits_per_pixel, &size_line, &endian);
	img.width = width;
	img.height = height;
	return (img);
	// draw_line
	// int i = 500;
	// while (i < width * height)
	// {
	// 		data_addr[i] = RED;			
	// 	i += width;
	// }
	
	// int y = 0;
	// int x = 500;
	// while (y < height)
	// {
	// 	data_addr[y * width + x] = RED;
	// 	y++;	
	// }


}

void	on_key_press(int key, void *param)
{
	t_vars *vars;

	vars = ((t_vars *)param);
	if (key == KEY_W)
		vars->player.y -= 50;
	if (key == KEY_A)
		vars->player.x -= 50;
	if (key == KEY_S)
		vars->player.y += 50;
	if (key == KEY_D)
		vars->player.x += 50;
	if (key == KEY_ESC)
	{
		printf("ESC\n");
		mlx_loop_end(vars->mlx);
	}
	if (vars->player.y > 430)
		vars->player.y = 430;
	if (vars->player.y < 0)
		vars->player.y = 0;
	if (vars->player.x > 670)
		vars->player.x = 670;
	if (vars->player.x < 0)
		vars->player.x = 0;
	ft_clear_image(vars->img);
	ft_draw_object(vars->img, vars->player, RED);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	printf("key = %i\n", key);
}

int	main()
{
	t_vars	vars;

	
	vars.player.x = 0;
	vars.player.y = 0;
 	vars.mlx = mlx_init();
	if (vars.mlx == (void*)0)
		return (-1);
	ft_map_check();
	vars.win = mlx_new_window(vars.mlx, 720, 480, "title");
	vars.img = create_img(vars.mlx, vars.img, 720, 480);
	ft_draw_object(vars.img, vars.player, RED);	
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, (void *)on_key_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
