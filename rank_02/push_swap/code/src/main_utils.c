/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:45:02 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/19 23:45:04 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	free_and_exit(t_node **stack, char **str, int free_arr)
{
	if (free_arr)
		free_double_arr_on_freeflag(str, 1);
	free_stack_on_freeflag(stack, 1);
	write(2, "Error\n", 6);
	exit (1);
}

void	free_stack_and_exit(t_node **stack)
{
	free_stack_on_freeflag(stack, 1);
	write(2, "Error\n", 6);
	exit (1);
}

int	free_stack_and_arr(t_node **stack, char **str, int free_arr)
{
	free_double_arr_on_freeflag(str, free_arr);
	free_stack_on_freeflag(stack, 1);
	return (0);
}
