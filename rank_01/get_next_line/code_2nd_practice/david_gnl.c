int	ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	if (c > 255)
		c %= 256;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (str[index] == c)
		return (index);
	return (-1);
}

//read the document by BUFFERSIZE, joining the leftover
//from previous call break if the '\n' is founded

char	*reader(int fd, char *left_over, char *buffer)
{
	ssize_t		bytes_read;
	char		*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE); // leftover: 88888888
		if (bytes_read < 0)
		{
			free(left_over);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left_over)
			left_over = ft_strdup("");
		tmp = left_over;
		left_over = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n') != -1)
			break ;
	}
	return (left_over);
}

//parse the line to next \n and return the leftover

char	*line_parse(char **line)
{
	char	*result;
	char	*tmp;
	int		lbreak_index;

	lbreak_index = 0;
	while ((*line)[lbreak_index] != '\n' && (*line)[lbreak_index] != '\0')
		lbreak_index++;
	lbreak_index = ft_strchr(*line, '\n');
	result = ft_substr(*line, lbreak_index + 1, ft_strlen(*line) - lbreak_index);
	if (!result)
		return (NULL);
	tmp = *line;
	*line = ft_substr(tmp, 0, lbreak_index + 1);
	if (!(*line))
		return (NULL);
	free(tmp);
	return (result);
}

//inital check, init. and alloc. return the line

char	*get_next_line(int fd)
{
	static char	*left_over = NULL;
	char		*line;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	line = reader(fd, left_over, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left_over = line_parse(&line);
	return (line);
}