/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:15:14 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/07 15:15:15 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	res;
	char			c;

	if (n >= 0)
		res = n;
	else
	{
		write(fd, "-", 1);
		res = -n;
	}
	if (res >= 10)
	{
		ft_putnbr_fd(res / 10, fd);
	}
	c = res % 10 + '0';
	write(fd, &c, 1);
}
