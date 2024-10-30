/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack0_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:06:08 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:06:09 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_last_node(t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!temp)
		return (NULL);
	while (temp->right)
		temp = temp->right;
	return (temp);
}

t_node	*get_max_node(t_node *stack)
{
	t_node		*cur;
	t_node		*max_node;

	if (!stack)
		return (NULL);
	cur = stack;
	max_node = stack;
	while (cur)
	{
		if (max_node->val < cur->val)
			max_node = cur;
		cur = cur->right;
	}
	return (max_node);
}

t_node	*get_min_node(t_node *stack)
{
	t_node		*cur;
	t_node		*min_node;

	if (!stack)
		return (NULL);
	cur = stack;
	min_node = stack;
	while (cur)
	{
		if (min_node->val > cur->val)
			min_node = cur;
		cur = cur->right;
	}
	return (min_node);
}

int	get_size(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->right;
	}
	return (i);
}

int	is_sorted(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->right)
		return (-1);
	temp = *stack;
	while (temp->right)
	{
		if (temp->val > temp->right->val)
		{
			return (0);
		}
		temp = temp->right;
	}
	return (1);
}
