#include "../includes/find_shortest.h"

/**
 * @brief open the file, validate it, close fd regardless of the result
 * @return 0, if not readable or if not a map
 * @return 1, if readable map
 */
int	is_readable_map(int fd, char *s)
{
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (0);
	if (ft_strcmp(s + strlen(s) - 4, ".ber"))
	{
		perror("File not '.ber'");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd = 0;
	//validate the map
	if (ac != 2)
		return (1);
	if (!is_readable_map(fd, av[1]))
		return (1);

	//open window


	//find the shortest path

	//if same, keep going, if not, show the shortest map -> terminate, clean exit

}
