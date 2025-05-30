/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:37:17 by                   #+#    #+#             */
/*   Updated: 2025/05/01 19:00:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (48 <= *str && *str <= 57)
	{
		n = (n * 10) + (*str - 48);
		str++;
	}
	return (n * sign);
}
