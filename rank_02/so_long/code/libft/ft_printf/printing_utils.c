/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:22:29 by jiepark           #+#    #+#             */
/*   Updated: 2024/11/15 13:22:47 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_ptr(unsigned long long int nb, int base)
{
	int		len;

	len = 0;
	if (!nb)
	{
		ft_putstr_fd("(nil)", 1);
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
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
