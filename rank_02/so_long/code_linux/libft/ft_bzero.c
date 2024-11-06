/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:43:25 by jiepark           #+#    #+#             */
/*   Updated: 2024/04/29 13:43:27 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*temp;
	unsigned int	i;

	temp = (char *) s;
	i = 0;
	while (i < (unsigned int)n)
	{
		temp[i] = 0;
		i++;
	}
}
