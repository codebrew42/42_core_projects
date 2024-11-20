/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:51:20 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/19 18:51:20 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <stdlib.h>
# include "../../../../rank_00/libft/code/includes/libft.h"

char		*update_stash(char *stash);
char		*extract_line(char *src);
char		*get_next_line(int fd);

//libft
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);

#endif