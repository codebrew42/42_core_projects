/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:01:59 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/07 18:01:59 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

int free_close_and_report_error(int fd, char *str_to_free, char *str)
{
    close(fd);
    free(str_to_free);
    ft_printf("Error: %d", str);
    return (1);
}

int free_and_report_error(char *str_to_free, char *str)
{
    free(str_to_free);
    ft_printf("Error: %d", str);
    return (1);
}

int report_error(char *str)
{
    ft_printf("Error: %d", str);
    return (1);
}