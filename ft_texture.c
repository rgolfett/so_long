/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:53:14 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/21 08:57:55 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_image_to_texture(t_vars vars)
{
	char	**texture;

	texture = mlx_xpm_file_to_image
		(vars.mlx, "touch grass", &vars.map.w, &vars.map.h);
	return (texture);
}
