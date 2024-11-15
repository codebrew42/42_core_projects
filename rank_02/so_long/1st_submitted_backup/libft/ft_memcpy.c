/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:33:09 by jiepark           #+#    #+#             */
/*   Updated: 2024/04/25 15:33:11 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;

	temp_dst = (char *)dst;
	temp_src = (const char *)src;
	if (!temp_dst && !temp_src)
		return (0);
	while (n--)
	{
		*temp_dst++ = *temp_src++;
	}
	return (dst);
}
