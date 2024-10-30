/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:11:39 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/07 15:11:40 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] && char_in_set(s1[i], set))
		i++;
	while (i <= j && char_in_set(s1[j], set))
		j--;
	result = malloc(j - i + 2);
	if (!result)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		result[k] = s1[i];
		i++;
		k++;
	}
	result[k] = '\0';
	return (result);
}
