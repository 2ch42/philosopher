/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:52:06 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/25 20:48:31 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include "philo.h"

static int	run_done(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->death));
	if (philo->data->die)
	{
		pthread_mutex_unlock(&(philo->data->death));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->death));
	pthread_mutex_lock(&(philo->data->eat));
	if (philo->eat_count == philo->data->arg->num_must)
	{
		pthread_mutex_unlock(&(philo->data->eat));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->eat));
	return (0);
}

void	run_philos(t_philo *philo)
{
	if (philo->num % 2 == 0)
		usleep (100);
	while (1)
	{
		if (run_done(philo) == 1)
			return ;
		pick_fork(philo);
		if (philo->data->arg->num_philos == 1)
			return ;
		philo_eat(philo);
		pthread_mutex_lock(&(philo->data->eat));
		if (philo->eat_count == philo->data->arg->num_must)
			philo->data->done_phil += 1;
		pthread_mutex_unlock(&(philo->data->eat));
		philo_sleep(philo);
		philo_print(philo, THINKING);
	}
}
