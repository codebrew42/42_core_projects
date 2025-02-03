# define BUFFER_SIZE 4096
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* my
void	ft_write(char *s, int len)
{
	int	i = -1;

	while (++i < len)
		write(1, &s[i], 1);
	//write(1, "\n", 1);
}

int	read_stdin(char *dest)
{
	char		*buff;
	int			bytes_read;
	ssize_t		total_len;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (1);
	}
	total_len = 0;
	while ((bytes_read = read(0, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		dest = malloc(total_len + bytes_read + 1);
		if (!dest)
			break ;
		memmove(dest + total_len, buff, bytes_read);
		total_len += bytes_read;
	}
	if (buff)
		free(buff);
	if (bytes_read < 0)
	{
		perror("Error");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		filter_len;
	char	*dest;

	if (ac != 2)
		return (1);

	read_stdin(dest);
//read buffer (from stdin)
	ft_write(dest, strlen(dest));
//read str (from input av[1])
	ft_write(av[1], strlen(av[1]));

	free(dest);
	return (0);
}
*/

char *read_stdin(void)
{
    char    buffer[BUFFER_SIZE];
    char    *content = NULL;
    size_t  capacity = 0;
    size_t  total_size = 0;
    ssize_t bytes_read;

    // Initial allocation
    capacity = BUFFER_SIZE;
    content = malloc(capacity);
    if (!content)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }

    while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
    {
        // Check if we need more space
        if (total_size + bytes_read >= capacity)
        {
            capacity = capacity * 2;
            char *new_content = realloc(content, capacity);
            if (!new_content)
            {
                fprintf(stderr, "Error: realloc failed\n");
                free(content);
                return (NULL);
            }
            content = new_content;
        }
        
        // Copy new data
        memmove(content + total_size, buffer, bytes_read);
        total_size += bytes_read;
    }

    if (bytes_read < 0)
    {
        perror("Error");
        free(content);
        return (NULL);
    }

    // Handle empty input
    if (total_size == 0)
    {
        content[0] = '\0';
        return (content);
    }

    // Final resize and null termination
    char *final = realloc(content, total_size + 1);
    if (final)
        content = final;
    content[total_size] = '\0';

    return (content);
}

int main(int ac, char **av)
{
    char *content;

    if (ac != 2)
        return (1);

    content = read_stdin();
    if (!content)
        return (1);

    // Use content here
    printf("%s", content);  // For testing

    free(content);
    return (0);
}