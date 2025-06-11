/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:15:45 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/07 15:15:46 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	len_n(int n);

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	big_n;
	char			*dest;

	len = len_n(n);
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	if (n > 0)
		big_n = (unsigned int)n;
	else
	{
		dest[0] = '-';
		big_n = -(unsigned int)n;
	}
	while (big_n >= 10)
	{
		dest[--len] = big_n % 10 + '0';
		big_n /= 10;
	}
	dest[--len] = big_n + '0';
	return (dest);
}

static int	len_n(int n)
{
	int				len;
	unsigned int	big_n;

	len = 1;
	if (n >= 0)
		big_n = n;
	else
	{
		len++;
		big_n = -(unsigned int)n;
	}
	while (big_n >= 10)
	{
		len++;
		big_n /= 10;
	}
	return (len);
}
