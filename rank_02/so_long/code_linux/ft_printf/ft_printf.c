#include "ft_printf.h"

int	print_formatted(const char c, va_list *args)
{
	if (c == 'c')
		return (print_char(va_arg(*args, int))); //read next args (where it points) as an int
	else if (c == 's')
		return (print_str(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (print_digit((long)va_arg(*args, int), 10, c));
	else if (c == 'u')
		return (print_digit((long)va_arg(*args, unsigned int), 10, c));
	else if (c == 'X' || c == 'x')
		return (print_digit((long)va_arg(*args, unsigned int), 16, c));
	else if (c == 'p')
		return (print_ptr((unsigned long long int)va_arg(*args, void *), 16));
	else if (c == '%')
		return (print_char('%'));
	return (-1);
}

int	ft_printf(const char *s, ...)
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
		{
			output_len += print_formatted(s[++i], &args);
			i++;
		}
		else
			output_len += print_char(s[i]);
		i++;
	}
	return (output_len);
}