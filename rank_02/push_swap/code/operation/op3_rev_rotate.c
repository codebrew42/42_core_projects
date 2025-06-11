/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:09:46 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:09:47 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*prev_tail;
	t_node	*cur;

	if (!stack || !(*stack) || !(*stack)->right)
		return ;
	cur = *stack;
	prev_tail = ft_last_node(cur);
	while (cur->right && cur->right != prev_tail)
		cur = cur->right;
	cur->right = NULL;
	prev_tail->right = *stack;
	(*stack)->left = prev_tail;
	prev_tail->left = NULL;
	*stack = prev_tail;
}

void	rev_rotate_a(t_node **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_node **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
