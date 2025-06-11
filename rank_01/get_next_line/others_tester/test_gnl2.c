/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:33:51 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/06/11 21:36:22 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_gnl.h"

int	main(int ac, char **av)
{
	char	*line;

	line = get_next_line(-1);
	if (!line)
		printf("fd -1: null\n\n");
	line = get_next_line(-42);
	if (!line)
		printf("fd -42: null\n\n");

	return (0);
}
