#include "so_long.h"


int	*ft_fill_tab(int *tab)
{
	int i;

	i = 0;
	while (i < 3)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int	ft_check_map_composure(char **map)
{
	int	x;
	int y;
	int tab[3];

	y = 0;
	ft_fill_tab(tab);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				tab[0]++;
			if (map[y][x] == 'C')
				tab[1]++;
			if (map[y][x] == 'E')
				tab[2]++;
			x++;
		}
		y++;
	}
	if (tab[0] != 1 || tab[2] != 1 || tab[1] == 0)
		return (printf("0\n"),-1);
	return (0);
}

int	ft_check_map_wall(char **map)
{
	int	x;
	int y;

	y = 0;
	x = 0;
	while (map[y][x] != '\n')
	{
		if (map[y][x] != '1')
			return (-1);
		x++;
	}
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][0] != '1')
				return (-1);
			x++;
		}
		if (map[y][x - 1] != '1')
			return (-1);
		y++;
	}
	x = 0;
	while (map[y - 1][x] != '\n')
	{
		if (map[y - 1][x] != '1')
			return (-1);
		x++;
	}
	return (0);
}

void	ft_find_player_pos(char **map, int *x, int *y)
{

	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x] != 'P')
			*x++;
		*y++;
	}
}

// int	ft_check_up_path(char **map, int x, int y)
// {
// 	if (map[y - 1][x] && map[y - 1][x] == '1')
// 		return (-1);
// 	if (map[y - 1][x])
// 		map[y - 1][x] == '1';
// 	return (0);
// }

// int	ft_check_down_path(char **map, int x, int y)
// {
// 	if (map[y + 1][x] && map[y + 1][x] == '1')
// 		return (-1);
// 	if (map[y + 1][x])
// 		map[y + 1][x] == '1';
// 	return (0);
// }

// int	ft_check_right_path(char **map, int x, int y)
// {
// 	if (map[y][x + 1] && map[y][x + 1] == '1')
// 		return (-1);
// 	if (map[y][x + 1])
// 		map[y][x + 1] == '1';
// 	return (0);
// }

// int	ft_check_left_path(char **map, int x, int y)
// {
// 	if (map[y][x - 1] && map[y][x - 1] == '1')
// 		return (-1);
// 	if (map[y][x - 1])
// 		map[y][x - 1] == '1';
// 	return (0);
// }

void	ft_check_flood(char **map_cpy, int x, int y)
{
	map_cpy[y][x] = '1';
	if (map_cpy[y][x - 1] != '1')
		ft_check_flood(map_cpy, (x - 1), y);
	if (map_cpy[y][x + 1] != '1')
		ft_check_flood(map_cpy, (x + 1), y);
	if (map_cpy[y - 1][x] != '1')
		ft_check_flood(map_cpy, x, (y - 1));
	if (map_cpy[y + 1][x] != '1')
		ft_check_flood(map_cpy, x, (y + 1));
}

int	ft_check_path(char **map_cpy)
{
	int y;
	int x;

	ft_find_player_pos(map_cpy, &x, &y);
	ft_check_flood(map_cpy, x, y);
}

int	ft_check_map_end(char **map)
{
	int	x;
	int y;
	int tab[4];

	y = 0;
	ft_fill_tab(tab);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				tab[0]++;
			if (map[y][x] == 'E')
				tab[1]++;
			x++;
		}
		y++;
	}
	if (tab[0] != 0 || tab[1] != 0 )
		return (printf("end\n"), -1);
	return (0);
}

char **ft_fill_cpy_map(char **map, char **map_cpy)
{
	int	x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map_cpy[y][x] = map[y][x];
			x++;
		}
		map_cpy[y][x] = '\0';
		y++;
	}
	map_cpy[y] = NULL;
	return (map_cpy);
}

char **ft_create_cpy_map(char **map)
{
	int	x;
	int y;
	char **map_cpy;

	y = 0;
	x = 0;
	while (map[y][x])
		x++;
	while (map[y])
		y++;
	map_cpy = malloc(sizeof(char *) * (y + 1));
		if (!map_cpy)
			return (NULL);
	while (y >= 0)
	{
		map_cpy[y] = malloc(sizeof(char) * (x + 1));
		if (!map_cpy[y])
			return (ft_free(map_cpy, y));
		y--;
	}
	ft_fill_cpy_map(map, map_cpy);
	return (map_cpy);
}

int	ft_check_map(char **map)
{
	char **map_cpy;
	int *x;
	int *y;

	if (ft_check_map_composure(map) == -1 || ft_check_map_wall(map) == -1)
		return (-1);
	map_cpy = ft_create_cpy_map(map);
	ft_check_path(map_cpy);
	if	(ft_check_map_end(map_cpy) == -1)
		return (printf("Impossible\n"), -1);
}