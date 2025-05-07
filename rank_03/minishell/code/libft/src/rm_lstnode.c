/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_lstnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:00:57 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/01 15:01:21 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rm_lstnode(t_list **lst, t_list *node)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == node)
		*lst = node->next;
	else
	{
		while (tmp->next && tmp->next != node)
			tmp = tmp->next;
		tmp->next = node->next;
	}
	ft_lstdelone(node, &free);
}
