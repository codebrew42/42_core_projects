/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:33:09 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/19 20:11:33 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/**
 * @brief	Copies `n` bytes(copy bytes by bytes) from the source memory area to the destination memory area.
 * 
 * when the source and destination memory areas don't overlap. If so, use 'memmove'
 *
 * @pre		The function does not check whether dest has enough allocated memory for  the n bytes. 
 * @pre		It only checks if dest or src is NULL. 
 * @pre		Therefore, it is the responsibility of the caller to ensure that dest has enough space. 
 * @param	dst Pointer to the destination memory area.
 * @param	src Pointer to the source memory area.
 * @param	n Number of bytes to copy.
 * @return	a pointer to the destination memory area (`dst`).
 * @return	NULL,  If either `dst` or `src` is NULL
 * @note	why using (const)unsigned char *? : just to move pointer byte by byte
 */
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
