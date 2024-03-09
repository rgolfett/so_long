/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:22:16 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/09 17:52:03 by rgolfett         ###   ########lyon.fr   */
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
	int	x;
	int	y;
} t_img;

void	*create_img(void *mlx, t_img img, int width, int height)
{
	void *window_img;
	unsigned int *data_addr;
	int bits_per_pixel;
	int size_line;
	int endian;

	window_img = mlx_new_image(mlx, width, height);
	data_addr = mlx_get_data_addr(window_img, &bits_per_pixel, &size_line, &endian);

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


	int y = 50;
	int x = 150;
	int width_sq = 50 + x;
	int height_sq = 50 + y;
	while (y < height_sq )
	{
		x = 150;
		while (x < width_sq)
		{
			data_addr[y * width + x] = RED;
			x++;
		}
		y++;	
	}	
	return (window_img);
}

void	on_key_press(int key, void *param)
{
	if (key == KEY_W)
		printf("w\n");
	if (key == KEY_A)
		printf("a\n");
	if (key == KEY_S)
		printf("s\n");
	if (key == KEY_D)
		printf("d\n");
	if (key == KEY_ESC)
	{
		printf("ESC\n");
		mlx_loop_end(param);
	}
	printf("key = %i\n", key);
}

int	main()
{
	void	*mlx;
	void	*win;
	t_img	window_img;
	

	mlx = mlx_init();
	if (mlx == (void*)0)
		return (-1);
	win = mlx_new_window(mlx, 720, 480, "title");
	window_img.img = create_img(mlx, window_img, 720, 480);
	mlx_put_image_to_window(mlx, win, window_img.img, 0, 0);
	
	mlx_key_hook(win, (void *)on_key_press, mlx);
	mlx_loop(mlx);
	return (0);
}
// w = 119
// a = 97
// s = 115
// d = 100

// esc = 65307