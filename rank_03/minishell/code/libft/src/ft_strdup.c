/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:40:37 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/04/09 22:19:24 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		i;

	if (!s)
		return (NULL);
	cp = malloc(ft_strlen(s) + 1);
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (*s)
		cp[i++] = *s++;
	cp[i] = '\0';
	return (cp);
}
