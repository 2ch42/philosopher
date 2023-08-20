/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:08:52 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/20 21:59:27 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

void	philo_print(t_philo *philo, char *status)
{
	unsigned long long	cur_time;

	pthread_mutex_lock(&(philo->data->print), NULL);
	cur_time = get_time();
	printf("%llu %d %s\n", cur_time - philo->data->start_time, philo->num, status);
	if (status == EATING)
		philo->last_meal = cur_time;
	pthread_mutex_unlock(&(philo->data->print), NULL);
}

void	pick_fork(t_philo *philo)
{
	unsigned long long start_time;

	pthread_mutex_lock(philo->forks[fork_l], NULL);
	philo_print(philo, FORK);
	pthread_mutex_lock(philo->forks[fork_r], NULL);
	philo_print(philo, FORK);
}

void	philo_eat(t_philo *philo)
{
	philo_print(philo, EATING);
	philo->eat_count++;
	pthread_mutex_unlock(data->print);
	pthread_mutex_unlock(data->forks);
	usleep(1000 * philo->data->arg->time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEPING);
	usleep(1000 * philo->data->arg->time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	philo_print(philo, THINKING);
}
