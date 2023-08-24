/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:08:52 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/24 22:48:49 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

void	philo_print(t_philo *philo, char *status)
{
	unsigned long long	cur_time;

	pthread_mutex_lock(&(philo->data->death));
	if (philo->data->die)
	{
		pthread_mutex_unlock(&(philo->data->death));
		return ;
	}
	pthread_mutex_unlock(&(philo->data->death));
	cur_time = get_time();
	pthread_mutex_lock(&(philo->data->print));
	printf("%llu %d %s\n", cur_time - philo->data->start_time,
		philo->num, status);
	pthread_mutex_unlock(&(philo->data->print));
	if (!ft_strncmp(status, EATING, 6))
	{
		pthread_mutex_lock(&(philo->time));
		philo->last_meal = cur_time;
		pthread_mutex_unlock(&(philo->time));
	}
}

void	pick_fork(t_philo *philo)
{
	if (!(pthread_mutex_lock(&(philo->data->forks[philo->fork_r]))))
		philo_print(philo, FORK);
	if (!(pthread_mutex_lock(&(philo->data->forks[philo->fork_l]))))
		philo_print(philo, FORK);
}

void	philo_eat(t_philo *philo)
{
	philo_print(philo, EATING);
	philo->eat_count++;
	pthread_mutex_lock(&(philo->data->eat));
	if (philo->eat_count == philo->data->arg->num_must)
	{
		philo->data->done_phil += 1;
		pthread_mutex_unlock(&(philo->data->eat));
		return ;
	}
	pthread_mutex_unlock(&(philo->data->eat));
	opt_timer(philo->data->arg->time_to_eat);
	pthread_mutex_unlock(&(philo->data->forks[philo->fork_r]));
	pthread_mutex_unlock(&(philo->data->forks[philo->fork_l]));
}

void	philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEPING);
	opt_timer(philo->data->arg->time_to_sleep);
}
