/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:32:10 by jiepark           #+#    #+#             */
/*   Updated: 2025/01/29 16:32:10 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	print_status_and_return_current_time(t_data *d, char *s, int p_id);
uint64_t	get_current_time(void);
int			print_err_msg(char *s);
int			print_err_msg_and_free(char *s, t_data **d);

uint64_t	print_status_and_return_current_time(t_data *d, char *s, int p_id)
{
	int		current_time;

	current_time = get_current_time();
	printf("%ld %d %s\n", current_time - d->start_time, p_id, s);
	return (current_time);
}

uint64_t	get_current_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	print_err_msg(char *s)
{
	printf("Error: %s", s);
	return (1);
}

int	print_err_msg_and_free(char *s, t_data **d)
{
	print_err_msg(s);
	free_data(d);
	return (1);
}