#include "so_long.h"

char **ft_image_to_texture(t_vars vars)
{
	char **texture;

	texture =  mlx_xpm_file_to_image(vars.mlx,"touch grass", &vars.map.w, &vars.map.h);
	return (texture);
}

