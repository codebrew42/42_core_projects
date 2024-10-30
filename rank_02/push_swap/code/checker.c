/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:06:17 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/19 20:06:17 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "libft/libft.h"

int	is_valid_op(char *line)
{
	int		i;
	char	*operations[12];

	operations[0] = "ra\n";
	operations[1] = "rb\n";
	operations[2] = "rr\n";
	operations[3] = "rra\n";
	operations[4] = "rrb\n";
	operations[5] = "rrr\n";
	operations[6] = "sa\n";
	operations[7] = "sb\n";
	operations[8] = "ss\n";
	operations[9] = "pa\n";
	operations[10] = "pb\n";
	operations[11] = NULL;
	i = 0;
	while (operations[i] != NULL)
	{
		if (!ft_strcmp(line, operations[i]))
			return (1);
		i++;
	}
	return (0);
}

int	execute_operation(char *line, t_node **stack_a, t_node **stack_b)
{
	if (!(ft_strcmp(line, "ra\n")))
		rotate_a(stack_a);
	else if (!(ft_strcmp(line, "rb\n")))
		rotate_b(stack_b);
	else if (!(ft_strcmp(line, "rr\n")))
		rotate_ab(stack_a, stack_b);
	else if (!(ft_strcmp(line, "rra\n")))
		rev_rotate_a(stack_a);
	else if (!(ft_strcmp(line, "rrb\n")))
		rev_rotate_b(stack_b);
	else if (!(ft_strcmp(line, "rrr\n")))
		rev_rotate_ab(stack_a, stack_b);
	else if (!(ft_strcmp(line, "sa\n")))
		swap_a(stack_a);
	else if (!(ft_strcmp(line, "sb\n")))
		swap_b(stack_b);
	else if (!(ft_strcmp(line, "ss\n")))
		swap_ab(stack_a, stack_b);
	else if (!(ft_strcmp(line, "pa\n")))
		push_a(stack_a, stack_b);
	else if (!(ft_strcmp(line, "pb\n")))
		push_b(stack_a, stack_b);
	return (0);
}

int	read_and_execute_operation(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	if (stack_a && *stack_a && !stack_b && is_sorted(stack_a))
	{
		write(1, "OK\n", 3);
		return (0);
	}
	line = get_next_line(0);
	while (line)
	{
		if (is_valid_op(line) == 0)
		{
			free(line);
			free_stack_on_freeflag(stack_b, 1);
			free_stack_and_exit(stack_a);
		}
		execute_operation(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

void	print_result(t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (*stack_a)
		free_stack_on_freeflag(stack_a, 1);
	if (*stack_b)
		free_stack_on_freeflag(stack_b, 1);
}

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	int			free_arr;

	stack_a = NULL;
	stack_b = NULL;
	free_arr = 0;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		argv = tokenize(argv[1], ' ');
		free_arr = 1;
	}
	init_stack_errcheck(&stack_a, argv, free_arr);
	if (!read_and_execute_operation(&stack_a, &stack_b))
		print_result(&stack_a, &stack_b);
	else if (!stack_b && is_sorted(&stack_a))
		write(1, "OK\n", 3);
	return (free_stack_and_arr(&stack_a, argv, free_arr));
}
