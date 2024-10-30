/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:09:50 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:09:51 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->right)
		return ;
	first = *stack;
	second = first->right;
	first->right = second->right;
	second->right = first;
	*stack = second;
}

void	swap_a(t_node **stack_a)
{
	swap(stack_a);
}

void	swap_b(t_node **stack_b)
{
	swap(stack_b);
}

void	swap_ab(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
