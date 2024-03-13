/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:29:37 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/13 11:28:01 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *string, int search)
{
	size_t	i;
	char	chr;

	chr = search % 256;
	i = 0;
	while (string[i])
	{
		if (string[i] == chr)
			return ((char *)&string[i]);
		i++;
	}
	if (!chr)
		return ((char *)&string[i]);
	return (NULL);
}
