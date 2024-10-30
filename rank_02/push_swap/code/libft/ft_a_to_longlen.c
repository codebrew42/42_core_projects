/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_longlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:13:09 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/19 16:33:36 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "libft.h"

int	ft_a_to_longlen(const char *str)
{
	int			len;

	len = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
	{
		str++;
		len++;
	}
	if (*str == '+' || *str == '-')
	{
		str++;
		len++;
	}
	while (*str >= '0' && *str <= '9')
	{
		str++;
		len++;
	}
	return (len);
}
