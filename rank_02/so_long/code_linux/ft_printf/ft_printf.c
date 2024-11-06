#include "ft_printf.h"

int print_formatted(const char c, va_list *args)
{
	unsigned int	len;

	len = 0;
	if (c == 'c')
		return (print_char(va_arg(*args, int))); //read next args (where it points) as an int
	else if (c == 's')
		return (print_str(va_arg(*args, char *)));

	return (len);
}

int	main(const char *s, ...)
{
	va_list			args;
	unsigned int	output_len;
	unsigned int	i;

	//to check: printf("hi") ; s points to "h"
	//to check: printf("%d", 101) ; s points to "%d", 
	va_start(args, s); 
	output_len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			output_len += print_formatted(s[++i], args);
		else
			output_len += print_char(s[i]);
		i++;
	}
	return (output_len);
}