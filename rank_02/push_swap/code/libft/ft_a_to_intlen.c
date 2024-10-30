/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_intlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:02:59 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/19 15:32:05 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_a_to_intlen(const char *str)
{
	int			len;

	len = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		str++;
		len++;
	}
	while (*str >= '0' && *str <= '9')
	{
		len++;
		str++;
	}
	return (len);
}
