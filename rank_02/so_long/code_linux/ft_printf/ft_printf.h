#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIERS "cspdiuxX%"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

# include <stdarg.h>


//printing.c
int		print_char(char c);

//utils.c
int		ft_strlen(char *str);

# endif