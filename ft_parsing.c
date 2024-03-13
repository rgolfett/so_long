#include "so_long.h"
#include "get_next_line.h"


int ft_check_cara(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
		return (-1);
	return (0);
}

int	ft_line_check(char *line)
{
	int i;

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

int ft_map_check(void)
{
	char *first_line;
	char *tmp;
	int fd;

	fd = open("map.ber", O_RDONLY);

	first_line = get_next_line(fd);
	tmp = first_line;
	if (first_line == NULL || ft_line_check(first_line) == -1)
		return (-1);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp != NULL && (ft_strlen(first_line) != ft_strlen(tmp)))
			return (printf("pas bon\n"), -1);
		if (ft_line_check(tmp) == -1)
			return (printf("bad line\n"), -1);
	}
	return (printf("c bon\n"), 0);
}