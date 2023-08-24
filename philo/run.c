/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:52:06 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/24 21:48:11 by changhyl         ###   ########.fr       */
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
	while (1)
	{
		pthread_mutex_lock(&(philo->data->death));
		if (philo->data->die)
		{
			pthread_mutex_unlock(&(philo->data->death));
			return ;
		}
		pthread_mutex_unlock(&(philo->data->death));
		pick_fork(philo);
		philo_eat(philo);
		pthread_mutex_lock(&(philo->data->eat));
		if (philo->eat_count == philo->data->arg->num_must)
		{
			pthread_mutex_unlock(&(philo->data->eat));
			return ;
		}
		pthread_mutex_unlock(&(philo->data->eat));
		philo_sleep(philo);
		philo_print(philo, THINKING);
	}
}
