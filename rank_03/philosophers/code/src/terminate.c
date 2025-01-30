/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:35:52 by jiepark          #+#    #+#              */
/*   Updated: 2024/12/25 20:35:52 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		join_threads(t_data *d, int n_philo);
void	free_data(t_data **d);
void	destroy_mutex(t_data *d);


