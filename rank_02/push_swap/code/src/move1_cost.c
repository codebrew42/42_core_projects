/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:05:55 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:05:56 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*set_and_get_cheapest_node(t_node *stack)
{
	t_node	*min_node;

	if (!stack)
		return (NULL); 
	min_node = stack;
	while (stack)
	{
		if (stack->cost < min_node->cost)
			min_node = stack;
		stack->cost_is_cheapest = 0;
		stack = stack->right;
	}
	min_node->cost_is_cheapest = 1;
	return (min_node);
}

void	set_cost_of_a(t_node *a, t_node *b)
{
	t_node	*a_cur;

	a_cur = a;
	while (a_cur)
	{
		if (a_cur->is_upper_mid && a_cur->target->is_upper_mid)
		{
			a_cur->cost = a_cur->target->idx;
			if (a_cur-> idx >= a_cur->target->idx)
				a_cur->cost = a_cur-> idx;
		}
		else if (!a_cur->is_upper_mid && !a_cur->target->is_upper_mid)
		{
			a_cur->cost = get_size(b) - a_cur->target->idx;
			if (get_size(a) - a_cur->idx >= get_size(b) - a_cur->target->idx)
				a_cur->cost = get_size(a) - a_cur->idx;
		}
		else if (a_cur->is_upper_mid && !a_cur->target->is_upper_mid)
			a_cur->cost = a_cur->idx + get_size(b) - a_cur->target->idx;
		else if (!a_cur->is_upper_mid && a_cur->target->is_upper_mid)
			a_cur->cost = get_size(a) - a_cur->idx + a_cur->target->idx;
		a_cur = a_cur->right;
	}
}
