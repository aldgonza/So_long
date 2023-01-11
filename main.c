#include "so_long.h"

char	**ft_map_test(fd)
{
	char	**map;
	char	*buffer;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	buffer = get_next_line(fd);
	size = ft_strlen_gnl(buffer);
	map = malloc(size + 1);
	if (!map)
		return (0);
	map[size + 1] = NULL;
	while(buffer != NULL)
	{
		map[i] = ft_strjoin_gnl(NULL, buffer);
		i++;
		buffer = get_next_line(fd);
	}
	return (map);
}

int	main()
{
	int		fd;
	int		i;
	char	**map;

	fd = open("map.ber", O_RDONLY);
	i = 0;
	map = ft_map_test(fd);
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	so_long(map);
		return (0);
}
