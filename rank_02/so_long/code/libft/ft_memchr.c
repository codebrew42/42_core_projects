/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:27:44 by jiepark           #+#    #+#             */
/*   Updated: 2024/04/26 15:27:45 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*new_s;
	unsigned char			new_c;

	new_s = s;
	new_c = c;
	while (n-- > 0)
	{
		if (*new_s == new_c)
			return ((void *)new_s);
		new_s++;
	}
	return (NULL);
}
