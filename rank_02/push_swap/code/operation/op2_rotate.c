/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:09:42 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:09:43 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->right)
		return ;
	last = *stack;
	*stack = (*stack)->right;
	(*stack)->left = NULL;
	second_last = ft_last_node(*stack);
	second_last->right = last;
	last->left = second_last;
	last->right = NULL;
}

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
