/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:52:06 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/24 17:12:20 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "philo.h"

void	run_philos(t_philo *philo)
{
	if (philo->num % 2 == 0)
		usleep (100);
	while (!(philo->die))
	{
		if (!(philo->die))
			pick_fork(philo);
		if (!(philo->die))
			philo_eat(philo);
		if (philo->eat_count == philo->data->arg->num_must)
			break ;
		if (!(philo->die))
			philo_sleep(philo);
		if (!(philo->die))
			philo_print(philo, THINKING);
	}
}
