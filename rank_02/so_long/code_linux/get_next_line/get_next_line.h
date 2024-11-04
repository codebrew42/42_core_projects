/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:33:36 by jiepark           #+#    #+#             */
/*   Updated: 2024/06/27 16:33:37 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_free_param(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int nbr);
int		ft_strchr_idx(const char *s, int c);
char	*get_next_line(int fd);

#endif
