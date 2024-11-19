/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:38:55 by jiepark           #+#    #+#             */
/*   Updated: 2024/04/25 17:38:56 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/**
 * @brief Locates the first occurrence of a character in a string.
 * 
 * This function scans the string pointed to by `s` for the first occurrence
 * of the character `c`. The terminating null character is considered to be
 * part of the string; therefore, if `c` is `'\0', the function will return
 * a pointer to the terminating null character.
 *
 * @param s The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the first occurrence of the character `c` in the
 *         string `s`, or NULL if the character is not found.
 * @note terminating '\\n' is also considered to be part of 's'
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
