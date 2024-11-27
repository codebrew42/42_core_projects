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

#include "includes/libft.h"

/**
 * @brief malloc and concatenates two strings, if any of the strings is NULL, returns NULL
 * @return (if successful) pointer to the new string
 * @return (else) NULL
 * @note 	need to be updated
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		total_len;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
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
