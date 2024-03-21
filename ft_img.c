/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:09:41 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/21 09:01:09 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_image(t_img img)
{
	ft_memset(img.data_addr, 0, sizeof(unsigned int)
		* (img.height * img.width));
}

t_img	load_img(void *mlx, t_img img, char *texture)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	img.img = mlx_xpm_file_to_image(mlx, texture, &img.width, &img.height);
	img.data_addr = (unsigned int *)
		mlx_get_data_addr(img.img, &bits_per_pixel, &size_line, &endian);
	return (img);
}

t_img	create_img(void *mlx, t_img img, int width, int height)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	img.img = mlx_new_image(mlx, width, height);
	img.data_addr = (unsigned int *)
		mlx_get_data_addr(img.img, &bits_per_pixel, &size_line, &endian);
	img.width = width;
	img.height = height;
	return (img);
}

void	ft_load_sprites(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, (vars->map.w * 50),
			(vars->map.h * 50), "so_long");
	vars->img = create_img(vars->mlx, vars->img,
			(vars->map.w * 50), (vars->map.h * 50));
	vars->floor = load_img(vars->mlx, vars->floor, "touch-grass.xpm");
	vars->wall = load_img(vars->mlx, vars->wall, "bush.xpm");
	vars->collectible = load_img(vars->mlx, vars->collectible,
			"pomegrenade.xpm");
	vars->player_tex = load_img(vars->mlx, vars->player_tex, "baby_gryff.xpm");
	vars->exit = load_img(vars->mlx, vars->exit, "exit.xpm");
}

void	ft_destroy_image(t_vars vars)
{
	if (vars.win != NULL)
		mlx_destroy_window(vars.mlx, vars.win);
	if (vars.img.img != NULL)
		mlx_destroy_image(vars.mlx, vars.img.img);
	if (vars.wall.img != NULL)
		mlx_destroy_image(vars.mlx, vars.wall.img);
	if (vars.floor.img != NULL)
		mlx_destroy_image(vars.mlx, vars.floor.img);
	if (vars.exit.img != NULL)
		mlx_destroy_image(vars.mlx, vars.exit.img);
	if (vars.collectible.img != NULL)
		mlx_destroy_image(vars.mlx, vars.collectible.img);
	if (vars.player_tex.img != NULL)
		mlx_destroy_image(vars.mlx, vars.player_tex.img);
	if (vars.mlx != NULL)
		mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	ft_free(vars.map.map, vars.map.h);
}
