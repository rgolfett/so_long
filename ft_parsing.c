/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgolfett <rgolfett@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:52:21 by rgolfett          #+#    #+#             */
/*   Updated: 2024/03/21 08:52:22 by rgolfett         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_check_cara(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
		return (-1);
	return (0);
}

int	ft_line_check(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (ft_check_cara(line[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_map_check(char *file, int *x, int *y)
{
	char	*first_line;
	char	*tmp;
	int		fd;
	int		nb_line;

	fd = open(file, O_RDONLY);
	first_line = get_next_line(fd);
	tmp = first_line;
	nb_line = 1;
	if (first_line == NULL || ft_line_check(first_line) == -1)
		return (ft_free2(first_line, tmp), -1);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		nb_line++;
		if (tmp != NULL && (ft_strlen(first_line) != ft_strlen(tmp)))
			return (ft_free2(first_line, tmp), -1);
		if (ft_line_check(tmp) == -1)
			return (ft_free2(first_line, tmp), -1);
		free (tmp);
	}
	*y = nb_line;
	*x = ft_strlen(first_line);
	return (ft_free2(first_line, tmp), 0);
}

char	**ft_fill_map(char *file, char **map, int y)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (i < (y - 1))
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (ft_free(map, i), NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_create_map(char *file, int *x, int *y)
{
	char	**map;

	if (ft_map_check(file, x, y) == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (*y + 1));
	if (!map)
		return (NULL);
	if (ft_fill_map(file, map, *y) == NULL)
		return (NULL);
	*x -= 1;
	*y -= 1;
	return (map);
}
