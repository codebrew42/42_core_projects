/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:33:18 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/15 11:22:25 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*temp_src;

	if (dst == src)
		return (dst);
	dst_ptr = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (dst > src)
	{
		while (len--)
			dst_ptr[len] = temp_src[len];
	}
	else
		while (len--)
			*dst_ptr++ = *temp_src++;
	return (dst);
}
