/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:05:37 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:05:38 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

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
	if (!is_sorted(&stack_a) && stack_a)
		sort(&stack_a, &stack_b);
	free_stack_and_arr(&stack_a, argv, free_arr);
	return (0);
}
