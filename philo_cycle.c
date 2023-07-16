/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:09:36 by changhyl          #+#    #+#             */
/*   Updated: 2023/07/16 21:21:48 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phil_print(char	*status, )

void	pick_fork(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(data->forks);
	philo->fork_l = 1;
	*(philo->fork_r) = 1;
	//printf
}

void	philo_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(data->print);
	//printf
	pthread_mutex_unlock(data->print);
	philo->eat_count++;
	philo->fork_l = 0;
	*(philo->fork_r) = 0;
	pthread_mutex_unlock(data->forks);
}

void	philo_death(t_arg *arg, t_data *data)
{
	//
}
