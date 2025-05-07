/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:13:42 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/05/08 23:21:28 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0 && ((unsigned char)*s1 || (unsigned char)*s2))
		if ((unsigned char)*s1++ != (unsigned char)*s2++)
			return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
	return (0);
}
