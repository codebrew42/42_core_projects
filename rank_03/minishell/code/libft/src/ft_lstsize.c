/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:14:19 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/05/06 22:14:46 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*tmp;

	if (!lst)
		return (0);
	n = 1;
	tmp = lst;
	while (tmp->next)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}
