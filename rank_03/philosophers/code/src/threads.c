/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:31:57 by jiepark           #+#    #+#             */
/*   Updated: 2025/01/29 16:31:58 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		*monitor(void *arg);
int			check_death(t_data *d, int n_philo);
int			check_end_condition(t_data *d, int n_philo);
int			launch_threads(t_data *d, int n_philo);
void		*routine(void *arg);
