/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:16:17 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/28 16:16:18 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

# define SPECIFIERS "cspdiuxX%"
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

//ft_printf
int		ft_printf(const char *s, ...);

//ft_printf_utils
void	ft_putstr(const char *s1);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
int		ft_strchr(char c, char *str);
int		ft_putnbr_len(unsigned int nb);

//ft_printf_print
int		print_digit(long nb, int base, char c);
int		print_str(char *str);
int		print_char(char c);
int		print_ptr(unsigned long long int nb, int base);
int		print_hexadigit(unsigned long long int nb, int base, char c);

#endif
