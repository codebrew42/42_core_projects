/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:05:21 by jiepark           #+#    #+#             */
/*   Updated: 2024/04/29 17:05:25 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total_size;
	char	*temp_ptr;

	total_size = count * size;
	result = malloc(total_size);
	if (result == NULL)
		return (NULL);
	temp_ptr = (char *)result;
	while (total_size-- > 0)
	{
		*temp_ptr = 0;
		temp_ptr++;
	}
	return (result);
}
