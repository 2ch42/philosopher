/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:08:52 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/23 22:14:41 by changhyl         ###   ########.fr       */
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

	pthread_mutex_lock(&(philo->data->print));
	cur_time = get_time();
	printf("%llu %d %s\n", cur_time - philo->data->start_time,
		philo->num, status);
	if (!ft_strncmp(status, EATING, 6))
		philo->last_meal = cur_time;
	pthread_mutex_unlock(&(philo->data->print));
}

void	pick_fork(t_philo *philo)
{
	unsigned long long	start_time;

	if (!(pthread_mutex_lock(&(philo->data->forks[philo->fork_l]))))
		philo_print(philo, FORK);
	if (!(pthread_mutex_lock(&(philo->data->forks[philo->fork_r]))))
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
