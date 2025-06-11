/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:06:57 by jiepark           #+#    #+#             */
/*   Updated: 2025/04/25 19:06:58 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_content(t_list **lst, void *content)
{
	t_list	*new_node;

	if (!lst || !content)
		return ;
	new_node = ft_lstnew(content);
	if (!new_node)
		return ;
	ft_lstadd_back(lst, new_node);
	return ;
}
