/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:55:35 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/24 16:44:49 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define BLACK	0x000000
# define WHITE	0xffffff
# define RED		0xff0000
# define GREEN	0x00ff00
# define BLUE	0x0000ff

typedef struct s_img
{
	void			*img;
	unsigned int	*data_addr;
	int				width;
	int				height;
}	t_img;

typedef struct s_object
{
	char	*texture;
	int		x;
	int		y;
}	t_object;

typedef struct s_map
{
	char	**map;
	int		w;
	int		h;
}	t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			movement;
	t_img		img;
	t_img		floor;
	t_img		wall;
	t_img		player_tex;
	t_object	player;
	t_img		collectible;
	t_map		map;
	t_img		exit;
}	t_vars;

char	*ft_strchr(const char *string, int search);
void	*ft_memset(void *s, int c, size_t size);
void	ft_putnbr_fd(int nb);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_draw_object(t_img img, t_object object, unsigned int color);

void	on_key_press(int key, void *param);

int		ft_check_cara(char c);
int		ft_line_check(char *line);
int		ft_map_check(char *file, int *x, int *y);
char	**ft_fill_map(char *file, char **map, int y);
char	**ft_create_map(char *file, int *x, int *y);

char	*ft_free(char **map, int i);
void	ft_free2(char *s1, char *s2);
void	ft_reverse_free(char **map_cpy, int y);

void	ft_display_map(t_vars vars);

void	ft_draw_texture(t_img img, t_object object, t_img texture);
int		ft_draw_floor(t_vars vars);
int		ft_draw_walls(t_vars vars);
int		ft_draw_collectibles(t_vars vars);
int		ft_draw_exit(t_vars vars);

int		ft_find_player(t_vars vars, int *x, int *y);

int		*ft_fill_tab(int *tab);

char	**ft_create_cpy_map(char **map);
char	**ft_fill_cpy_map(char **map, char **map_cpy);

int		ft_valid_file(char *file);
int		ft_check_map(char **map);
int		ft_check_map_composure(char **map);
int		ft_check_map_wall(char **map);
void	ft_check_flood(char **map_cpy, int x, int y);
void	ft_check_path(char **map_cpy);
int		ft_check_map_end(char **map);

void	ft_find_player_pos(char **map, int *x, int *y);
int		ft_check_player_pos(t_vars vars);

void	ft_clear_image(t_img img);
t_img	load_img(void *mlx, t_img img, char *texture);
t_img	create_img(void *mlx, t_img img, int width, int height);
int		ft_load_sprites(t_vars *vars);
void	ft_destroy_image(t_vars vars);

void	ft_key_press(t_vars *vars, int key);

void	ft_check_exit_condition(t_vars vars);
int		ft_close(t_vars *vars);

#endif