/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:03:14 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/06/18 21:12:46 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_GNL_H
# define TEST_GNL_H

#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line.h"

# ifndef FILE_NAME
#  define FILE_NAME "test/test1.txt"
//#  define FILE_NAME "test1.txt"
# endif

void	ft_call_print_gnl(int fd);
#endif
