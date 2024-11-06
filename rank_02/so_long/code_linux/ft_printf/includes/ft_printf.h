#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIERS "cspdiuxX%"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

# include <stdarg.h>

//ft_printf
int		ft_printf(const char *s, ...);

//printing.c
int		print_digit(long nb, int base, char c);
int		print_str(char *str);
int		print_char(char c);
int		print_ptr(unsigned long long int nb, int base);
int		print_hexadigit(unsigned long long int nb, int base, char c);

# endif