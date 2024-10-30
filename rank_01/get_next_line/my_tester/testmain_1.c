#include "../code/get_next_line.h"
#include <stdio.h>

int	main()
{
	char	*str;
	char	*str2;
	
	str = ft_strndup("hello jieun", 7);
	printf("%s", str);
	printf("%s", ft_strchr(str2, '\n'));
}
