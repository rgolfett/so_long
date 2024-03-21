/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:40:27 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/21 08:36:51 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_reverse_free(char **map_cpy, int y)
{
	while (map_cpy[y])
	{
		free(map_cpy[y]);
		y++;
	}
	free(map_cpy);
}

char	*ft_free(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	return (NULL);
}

void	ft_free2(char *s1, char *s2)
{
	free (s1);
	free (s2);
}
