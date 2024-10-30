/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:54:55 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/15 11:20:34 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i ;
	size_t	len_src;
	size_t	len_dst;
	int		j;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (!src || dstsize < len_dst + 1)
		return (dstsize + len_src);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len_dst + len_src);
}
