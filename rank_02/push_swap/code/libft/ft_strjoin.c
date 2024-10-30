/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:08:15 by jiepark           #+#    #+#             */
/*   Updated: 2024/04/30 17:08:16 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		total_len;
	char	*dest;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	dest = ft_calloc(total_len + 1, 1);
	if (!dest)
		return (NULL);
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	dest -= total_len;
	return (dest);
}
