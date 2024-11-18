#include "../code/get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	//fd = open("", O_RDONLY);
	//fd = open(NULL, O_RDONLY);
	//fd = open("map1-1.ber", O_RDONLY);
	//fd = open("map1-2.ber", O_RDONLY);
	if (fd < 0)
		return (1);
	// line = get_next_line(fd);
	// if (!line)
	// 	printf("null");
	// line = get_next_line(fd);
	// if (!line)
	// 	printf("null");
	 while (1)
	 {
	 	line = get_next_line(fd);
		if (!line)
		{
	 		puts("null");
	 		break;
	 	}
	 	printf("%s", line);
	 	free(line);
	 }
	close(fd);
	get_next_line(-1); //for freeing stash
	return (0);
}

