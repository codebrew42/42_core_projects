/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:06:00 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:06:01 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	double_rotation(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;
	t_node	*a_current;
	t_node	*b_current;

	a_current = *stack_a;
	b_current = *stack_b;
	cheapest = set_and_get_cheapest_node(a_current);
	if (!cheapest || !cheapest->target)
		return ;
	while (a_current != cheapest && b_current != cheapest->target)
	{
		if (cheapest->is_upper_mid && cheapest->target->is_upper_mid)
			rotate_ab(stack_a, stack_b);
		else if (!cheapest->is_upper_mid && !cheapest->target->is_upper_mid)
			rev_rotate_ab(stack_a, stack_b);
		else
			break ;
		a_current = *stack_a;
		b_current = *stack_b;
	}
}

void	single_rotation(t_node **stack, t_node *top_node, int is_a)
{
	while (*stack != top_node)
	{
		if (is_a && top_node->is_upper_mid)
			rotate_a(stack);
		else if (is_a && !top_node->is_upper_mid)
			rev_rotate_a(stack);
		else if (!is_a && top_node->is_upper_mid)
			rotate_b(stack);
		else if (!is_a && !top_node->is_upper_mid)
			rev_rotate_b(stack);
	}
}

void	a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = set_and_get_cheapest_node(*stack_a);
	init_nodes_a(*stack_a, *stack_b);
	get_target_of_a(*stack_a, *stack_b);
	while (get_size(*stack_a) > 3 && !is_sorted(stack_a))
	{
		double_rotation(stack_a, stack_b);
		single_rotation(stack_a, cheapest, 1);
		single_rotation(stack_b, cheapest->target, 0);
		push_b(stack_a, stack_b);
		init_nodes_a(*stack_a, *stack_b);
		cheapest = set_and_get_cheapest_node(*stack_a);
		get_idxinfo(*stack_a, get_size(*stack_a));
		get_idxinfo(*stack_b, get_size(*stack_b));
	}
}

void	b_to_a(t_node **stack_a, t_node **stack_b)
{
	int		b_len;

	b_len = get_size(*stack_b);
	while (b_len > 0)
	{
		init_nodes_b(*stack_a, *stack_b);
		single_rotation(stack_a, (*stack_b)->target, 1);
		push_a(stack_a, stack_b);
		b_len = get_size(*stack_b);
	}
}

void	min_to_top(t_node **stack_a)
{
	t_node	*min_node;

	min_node = get_min_node(*stack_a);
	get_idxinfo(*stack_a, get_size(*stack_a));
	while ((*stack_a)->val != min_node->val)
	{
		if (min_node->is_upper_mid)
			rotate_a(stack_a);
		else
			rev_rotate_a(stack_a);
	}
}
