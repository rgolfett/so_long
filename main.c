/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:22:16 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/12 23:11:22 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

#define BLACK	0x000000
#define WHITE	0xffffff
#define RED		0xff0000
#define GREEN	0x00ff00
#define BLUE	0x0000ff

#define img_width = 720
#define img_height = 480

typedef	struct s_img
{
	void *img;
	unsigned int *data_addr;
	int width;
	int height;
} t_img;

typedef struct s_player
{
	//t_img img;
	int	x;
	int	y;
} t_player;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_img	img;
	t_player player;
} t_vars;

void	*ft_memset(void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (size > 0)
	{
		str[i] = c;
		i++;
		size--;
	}
	return (str);
}

void	ft_clear_image(t_img img)
{
	ft_memset(img.data_addr, 0, sizeof(unsigned int) * (img.height * img.width));
}

void ft_draw_player(t_img img, t_player player)
{
	int tmp;
	int width_sq = 50 + player.x;
	int height_sq = 50 + player.y;
	while (player.y < height_sq)
	{
		tmp = player.x;
		while (player.x < width_sq)
		{
			img.data_addr[player.y * img.width + player.x] = RED;
			player.x++;
		}
		player.y++;
		player.x = tmp;
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
	ft_clear_image(vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_draw_player(vars->img, vars->player);
	printf("key = %i\n", key);
}

int	main()
{
	t_vars	vars;

	
	vars.player.x = 300;
	vars.player.y = 400;
 	vars.mlx = mlx_init();
	if (vars.mlx == (void*)0)
		return (-1);
	vars.win = mlx_new_window(vars.mlx, 720, 480, "title");
	vars.img = create_img(vars.mlx, vars.img, 720, 480);
	ft_draw_player(vars.img, vars.player);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, (void *)on_key_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
// w = 119
// a = 97
// s = 115
// d = 100

// esc = 65307