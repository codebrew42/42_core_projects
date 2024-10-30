/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:06:18 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:06:22 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	t_node	*min_node;

	min_node = get_min_node(*stack_a);
	if (ft_last_node(*stack_a) == min_node)
		rev_rotate_a(stack_a);
	while (*stack_a != min_node)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !*stack_a 
		|| !(*stack_a)->right || !(*stack_a)->right->right)
		return ;
	a = (*stack_a)->val;
	b = (*stack_a)->right->val;
	c = (*stack_a)->right->right->val;
	if (a > b && a > c)
		rotate_a(stack_a);
	else if (b > a && b > c)
		rev_rotate_a(stack_a);
	if ((*stack_a)->val > (*stack_a)->right->val)
		swap_a(stack_a);
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	int		a_size;

	a_size = get_size(*stack_a);
	if (a_size == 2)
		swap_a(stack_a);
	else if (a_size == 3)
		sort_three(stack_a);
	else if (a_size == 4)
		sort_four(stack_a, stack_b);
	else if (a_size >= 5)
	{
		if (get_size(*stack_a) != 4)
			push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		a_to_b(stack_a, stack_b);
		sort_three(stack_a);
		get_idxinfo(*stack_a, get_size(*stack_a));
		b_to_a(stack_a, stack_b);
		min_to_top(stack_a);
	}
}
