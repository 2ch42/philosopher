/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:17:00 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/20 20:14:46 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "philo.h"

void	pthread_mutex_init_s(pthread_mutex_t *mutex)
{
	if (pthread_mutx_init(mutex, NULL))
		write(2, "mutex init occured!\n", 20);
}

unsigned long long	get_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void	free_clear(t_arg *arg, t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < arg->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->count));
	pthread_mutex_destroy(&(data->death));
	free(philos);
	free(data->forks);
	data->forks = NULL;
}
