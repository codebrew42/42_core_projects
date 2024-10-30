/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:34:05 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/28 16:34:05 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_strchr(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_putnbr_len(unsigned int nb)
{
	char			c;
	int				len;

	len = 0;
	if (nb >= 10)
		len += ft_putnbr_len(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
	len++;
	return (len);
}

void	ft_putstr(const char *s1)
{
	while (*s1)
	{
		write(1, s1, 1);
		s1++;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	res = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
