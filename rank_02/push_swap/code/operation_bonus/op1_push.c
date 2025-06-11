/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:09:38 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:09:38 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->right;
	if (*src)
		(*src)->left = NULL;
	temp->right = *dest;
	if (*dest)
		(*dest)->left = temp;
	temp->left = NULL;
	*dest = temp;
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
}
