# issue 1: reading unitialized static var
- static var is initialized to NULL by default, I didn't explicitlyinitialize it and tried to read it 
: read(fd, stash, BUFFER_SIZE)
- so, it caused error.(bad address)

## code
```c
char	*get_next_line(int fd)
{
	static char	*stash;
	int			bytes_read;

	bytes_read = read(fd, stash, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		perror("error"); //output: error: Bad address
		free(stash);
		return (NULL);
	}
	//exising code
}

int	main(void)
{
	//existing code
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			return (NULL);
	}
	//existing code
}
```

# issue 2: how to free extracted line while returning that line
```c
char	*get_next_line(int fd)
{
	char			*line;
	int				bytes_read;
	static char		*stash;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!stash)
	{
		stash = malloc(BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		bytes_read = read(fd, stash, BUFFER_SIZE);
		stash[BUFFER_SIZE] = '\0';
		if (bytes_read <= 0)
		{
			free(stash);
			return (NULL);
		}
	}
	extract_line(stash, line); //extract line from stash to line
	stash = update_stash(stash);
	return (line);
}

char	*extract_line(char *src, char *dst)
{
	if (!dst)
		return (NULL);
	//malloc and copy src or a part of src reading untill the first '\n' of the src.
	return (dst);
}
```
- freeing line which is read by get_next_line() is the caller's responsibility, which means
the main() should free the line!, not the get_next_line


## issue 3 : seg fault
```c
#include "includes/get_next_line.h"

char	*update_stash(char *stash)
{
	char	*res;

	if (!stash)
		return (NULL);
	res = ft_strchr(stash, '\n');
	if (*res == '\n')
		res++;
	return (res);
}

char	*extract_line(char *src)
{
	char	*end_of_line;
	char	*dest;
	char	*temp_src;
	int		len;

	if (!src)
		return (NULL);
	end_of_line = ft_strchr(src, '\n');
	if(!end_of_line)
		len = ft_strlen(src);
	else
	{
		temp_src = src;
		len = 0;
		while (*temp_src++ != *end_of_line) //to check
			len++;
	}
	printf("extracted line: len(%d)", len); //rm
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	dest = ft_memcpy(dest, src, len);
	dest[len] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char			*line;
	int				bytes_read;
	static char		*stash;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!stash || stash == '\0')
	{
		stash = malloc(BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		bytes_read = read(fd, stash, BUFFER_SIZE);
		stash[BUFFER_SIZE] = '\0';
		if (bytes_read <= 0)
		{
			free(stash);
			return (NULL);
		}
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY); //(!)
	if (fd < 0)
		return (1);
	// if (read(fd, NULL, 0) < 0) // necessary?
	// {
	// 	return (1);
	// }
	int i = 0; //rm
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("\tof funcion call(%d): %s\n", i++, line); //rm
		free(line);
	}
	close(fd); //(!)
	return (0);
}
```
