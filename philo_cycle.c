/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:09:36 by changhyl          #+#    #+#             */
/*   Updated: 2023/07/17 15:26:22 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

void	philo_print(t_data *data, t_philo *philo, char *status)
{
	unsigned long long	cur_time;

	pthread_mutex_lock(data->print, NULL);
	cur_time = get_time();
	printf("%llu %d %s\n", cur_time - data->start_time, philo->num, status);
	pthread_mutex_unlock(data->print, NULL);
}

void	pick_fork(t_data *data, t_philo *philo)
{
	unsigned long long start_time;

	pthread_mutex_lock(data->forks, NULL);
	if (philo->fork_l == 0)
		philo->fork_l = 1;
	if (*(philo->for_r) 
	//print
}

void	philo_eat(t_data *data, t_philo *philo)
{
	//print
	philo->eat_count++;
	philo->fork_l = 0;
	*(philo->fork_r) = 0;
	pthread_mutex_unlock(data->print);
	pthread_mutex_unlock(data->forks);
}

void	philo_death(t_arg *arg, t_data *data)
{
	//
}
