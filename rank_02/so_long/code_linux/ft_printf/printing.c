#include "ft_printf.h"

/*note
print_char : &c

*/

int	print_str(char *str)
{
	while (*str)
		write(1, (*str)++, 1);
	return (ft_strlen(str));
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}