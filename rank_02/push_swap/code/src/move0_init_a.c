/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move0_init_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:05:44 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:05:44 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_idxinfo(t_node *a, int a_size)
{
	int		i;
	int		mid;

	if (!a || !a_size)
		return ;
	i = 0;
	mid = a_size / 2;
	while (a)
	{
		a->is_upper_mid = 0;
		if (i <= mid)
			a->is_upper_mid = 1;
		a->idx = i;
		i++;
		a = a->right;
	}
}

t_node	*get_any_b_smaller_than_a(t_node *a, t_node *b)
{
	if (!b)
		return (NULL);
	while (b)
	{
		if (b->val < a->val)
			return (b);
		b = b->right;
	}
	return (NULL);
}

void	get_target_of_a(t_node *a, t_node *b)
{
	t_node	*b_cur;
	t_node	*closest_smaller;

	while (a)
	{
		if (!b)
			break ;
		b_cur = b;
		closest_smaller = get_any_b_smaller_than_a(a, b_cur);
		while (b_cur)
		{
			if (!closest_smaller)
				break ;
			if (b_cur->val < a->val 
				&& a->val - b_cur->val < a->val - closest_smaller->val)
				closest_smaller = b_cur;
			b_cur = b_cur->right;
		}
		if (!closest_smaller)
			a->target = get_max_node(b);
		else
			a->target = closest_smaller;
		a = a->right;
	}
}

void	init_nodes_a(t_node *stack_a, t_node *stack_b)
{
	int		a_size;
	int		b_size;

	a_size = get_size(stack_a);
	b_size = get_size(stack_b);
	get_idxinfo(stack_a, a_size);
	get_idxinfo(stack_b, b_size);
	get_target_of_a(stack_a, stack_b);
	set_cost_of_a(stack_a, stack_b);
	set_and_get_cheapest_node(stack_a);
}
