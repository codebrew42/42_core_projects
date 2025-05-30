/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:33:56 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/28 16:33:57 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_ptr(unsigned long long int nb, int base)
{
	int		len;

	len = 0;
	if (!nb)
	{
		ft_putstr("(nil)");
		return (5);
	}
	write(1, "0x", 2);
	len += 2;
	return (print_hexadigit((unsigned long long int)nb, base, 'x') + len);
}

int	print_hexadigit(unsigned long long int nb, int base, char c)
{
	int		len;
	char	*nb_base;

	len = 0;
	nb_base = HEX_BASE_LOWER;
	if (c == 'X')
		nb_base = HEX_BASE_UPPER;
	if (nb >= (unsigned long long int)base)
		len += print_digit (nb / base, base, c);
	len += print_char(nb_base[nb % base]);
	return (len);
}

int	print_digit(long nb, int base, char c)
{
	int						len;
	char					*nb_base;
	unsigned long long int	big_nb;

	len = 0;
	nb_base = HEX_BASE_LOWER;
	if (c == 'X')
		nb_base = HEX_BASE_UPPER;
	if (nb < 0)
	{
		len += print_char('-');
		big_nb = (unsigned long long int)(-nb);
	}
	else
		big_nb = (unsigned long long int)nb;
	if (big_nb >= (unsigned long long int)base)
		len += print_digit (big_nb / base, base, c);
	len += print_char(nb_base[big_nb % base]);
	return (len);
}

int	print_str(char *str)
{
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
