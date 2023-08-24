/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:19:53 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/24 17:15:47 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

static void	check_death(t_arg *arg, t_data *data, t_philo *philos)
{
	int	i;
	int	j;

	j = 0;
	while (1)
	{
		i = 0;
		while (i < arg->num_philos)
		{
			pthread_mutex_lock(&(data->death));
			if (get_time() - philos[i].last_meal >= arg->time_to_die)
			{
				while (j < arg->num_philos)
				{
					philos[j++].die = 1;
					data->die = 1;
				}
				philo_print(&(philos[i]), DIED);
				pthread_mutex_unlock(&(data->death));
				return ;
			}
			pthread_mutex_unlock(&(data->death));
			i++;
		}
	}
}

static void	init_thread(t_arg *arg, t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < arg->num_philos)
	{
		philos[i].last_meal = data->start_time;
		if (pthread_create(&(philos[i].thread), NULL, (void *)run_philos,
				&(philos[i])))
			write(2, "pthread create error!\n", 22);
		i++;
	}
}

static void	init_philos(t_arg *arg, t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < arg->num_philos)
	{
		philos[i].data = data;
		philos[i].num = i + 1;
		philos[i].fork_r = i;
		if (i != 0)
			philos[i].fork_l = i - 1;
		philos[i].eat_count = 0;
		philos[i].last_meal = 0;
		philos[i++].die = 0;
	}
	philos[0].fork_l = arg->num_philos - 1;
	init_thread(arg, data, philos);
	check_death(arg, data, philos);
	free_clear(arg, data, philos);
}

int	init_data(t_arg *arg, t_data *data)
{
	int		i;
	t_philo	*philos;

	data->start_time = get_time();
	data->arg = arg;
	philos = (t_philo *)malloc(sizeof(t_philo) * arg->num_philos);
	if (!philos)
		return (0);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* arg->num_philos);
	if (!data->forks)
	{
		free(philos);
		philos = NULL;
		return (0);
	}
	i = 0;
	data->die = 0;
	while (i < arg->num_philos)
		pthread_mutex_init_s(&(data->forks[i++]));
	pthread_mutex_init_s(&(data->print));
	pthread_mutex_init_s(&(data->death));
	init_philos(arg, data, philos);
	return (1);
}
