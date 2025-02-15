/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:59:02 by jiepark           #+#    #+#             */
/*   Updated: 2025/02/06 19:59:03 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int			ft_strcmp(char *s1, char *s2);
uint64_t	str_to_uint64(char *s);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}

uint64_t	str_to_uint64(char *s)
{
	long	res;
	long	temp;
	int		i;

	if (!s)
		return (0);
	res = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
		{
			return (0);
		}
		temp = s[i] - 48;
		res = res * 10 + temp;
		i++;
	}
	if (res > INT_MAX)
		return (0);
	return ((uint64_t)res);
}
