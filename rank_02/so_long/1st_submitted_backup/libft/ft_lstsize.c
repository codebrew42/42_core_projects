/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:14:39 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/14 17:14:40 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	nb;

	nb = 0;
	while (lst)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}
