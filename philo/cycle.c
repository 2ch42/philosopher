/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:08:52 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/25 20:44:30 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

static int	done_print(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->death));
	if (philo->data->die)
	{
		pthread_mutex_unlock(&(philo->data->death));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->death));
	pthread_mutex_lock(&(philo->data->eat));
	if (philo->data->done_phil == philo->data->arg->num_philos)
	{
		pthread_mutex_unlock(&(philo->data->eat));
		return (1);
	}
	if (philo->eat_count == philo->data->arg->num_must)
	{
		pthread_mutex_unlock(&(philo->data->eat));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->eat));
	return (0);
}

void	philo_print(t_philo *philo, char *status)
{
	unsigned long long	cur_time;

	if (done_print(philo))
		return ;
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
	if (philo->data->arg->num_philos == 1)
		return ;
	if (!(pthread_mutex_lock(&(philo->data->forks[philo->fork_l]))))
		philo_print(philo, FORK);
}

void	philo_eat(t_philo *philo)
{
	philo_print(philo, EATING);
	philo->eat_count++;
	opt_timer(philo->data->arg->time_to_eat);
	pthread_mutex_unlock(&(philo->data->forks[philo->fork_r]));
	pthread_mutex_unlock(&(philo->data->forks[philo->fork_l]));
}

void	philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEPING);
	opt_timer(philo->data->arg->time_to_sleep);
}
