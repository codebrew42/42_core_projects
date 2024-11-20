/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:32:01 by jiepark           #+#    #+#             */
/*   Updated: 2024/11/15 10:32:02 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_formatted(const char c, va_list *args)
{
	if (c == 'c')
		return (print_char(va_arg(*args, int)));
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
	unsigned int	ret;

	ret = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *++s)
		{
			ret += print_formatted(*s, &args);
			s++;
		}
		else
		{
			ret += print_char(*s);
			s++;
		}
	}
	va_end(args);
	return (ret);
}
