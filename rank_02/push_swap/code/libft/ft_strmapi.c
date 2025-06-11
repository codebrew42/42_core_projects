/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:07 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/07 15:17:09 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	dest = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
