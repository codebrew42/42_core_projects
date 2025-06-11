/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:06:14 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:06:14 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	have_same_nbr(t_node *tmp)
{
	t_node	*current;

	if (!tmp)
		return (0);
	while (tmp)
	{
		current = tmp->right;
		while (current)
		{
			if (tmp->val == current->val)
				return (1);
			current = current->right;
		}
		tmp = tmp->right;
	}
	return (0);
}

int	is_numerics(char *str)
{
	int	i;
	int	has_digits;

	i = 0;
	has_digits = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		has_digits = 1;
		i++;
	}
	if (has_digits)
		return (1);
	else
		return (0);
}

int	build_node(t_node **stack_a, int nb)
{
	t_node		*cur;
	t_node		*last;

	cur = malloc(sizeof(t_node));
	if (!cur)
		return (1);
	cur->val = nb;
	cur->right = NULL;
	cur->cost = 0; 
	cur->idx = 0;
	cur->is_upper_mid = 0;
	cur->target = NULL;
	cur->cost_is_cheapest = 0;
	if (!*stack_a)
	{
		cur->left = NULL;
		*stack_a = cur;
	}
	else
	{
		last = ft_last_node(*stack_a);
		last->right = cur;
		cur->left = last;
	}
	return (0);
}

void	free_stack_on_freeflag(t_node **stack, int free_flag)
{
	t_node	*cur;
	t_node	*next;

	if (!free_flag)
		return ;
	cur = *stack;
	while (cur)
	{
		next = cur->right;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}

int	init_stack_errcheck(t_node **stack_a, char **av, int free_arr)
{
	long	nb;
	int		i;

	i = 0;
	if (free_arr == 0)
		i++;
	while (av[i])
	{
		if (!is_numerics(av[i]))
			free_and_exit(stack_a, av, free_arr);
		nb = ft_atol(av[i]);
		if (nb > (long)INT_MAX || nb < (long)INT_MIN)
			free_and_exit(stack_a, av, free_arr);
		if (build_node(stack_a, nb))
		{
			free_and_exit(stack_a, av, free_arr);
		}
		i++;
	}
	if (*stack_a && have_same_nbr(*stack_a))
		free_and_exit(stack_a, av, free_arr);
	return (0);
}
