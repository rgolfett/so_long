#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

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

#define img_width = 720
#define img_height = 480

typedef	struct s_img
{
	void *img;
	unsigned int *data_addr;
	int width;
	int height;
} t_img;

typedef struct s_object
{
	//t_img img;
	int	x;
	int	y;
} t_object;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_img	img;
	t_object player;
} t_vars;

char	*ft_strchr(const char *string, int search);
void	*ft_memset(void *s, int c, size_t size);

void	ft_clear_image(t_img img);
void	ft_draw_object(t_img img, t_object object, unsigned int color);

t_img	create_img(void *mlx, t_img img, int width, int height);

void	on_key_press(int key, void *param);

int ft_map_check(void);

#endif

