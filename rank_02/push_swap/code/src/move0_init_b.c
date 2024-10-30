/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move0_init_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:05:49 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:05:50 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_any_a_bigger_than_b(t_node *a, t_node *b)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->val > b->val)
			return (a);
		a = a->right;
	}
	return (NULL);
}

void	get_target_of_b(t_node *a, t_node *b)
{
	t_node	*a_cur;
	t_node	*closest_bigger;

	while (b)
	{
		if (!a)
			break ;
		a_cur = a;
		closest_bigger = get_any_a_bigger_than_b(a, b);
		while (a_cur)
		{
			if (!closest_bigger)
				break ;
			if (a_cur->val > b->val
				&& a_cur->val - b->val < closest_bigger->val - b->val)
				closest_bigger = a_cur;
			a_cur = a_cur->right;
		}
		if (!closest_bigger)
			b->target = get_min_node(a);
		else
			b->target = closest_bigger;
		b = b->right;
	}
}

void	init_nodes_b(t_node *stack_a, t_node *stack_b)
{
	int		a_size;
	int		b_size;

	a_size = get_size(stack_a);
	b_size = get_size(stack_b);
	get_idxinfo(stack_a, a_size);
	get_idxinfo(stack_b, b_size);
	get_target_of_b(stack_a, stack_b);
}
