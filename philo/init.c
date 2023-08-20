/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:19:53 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/20 03:09:47 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(arg, data)
{
	int	i;

	i = 0;
	while (i < arg->num_philos)
	{
		pthread_create(data->philos[i].thread, NULL, ~, ~);
		data->philos[i].num = i + 1;
		data->philos[i].fork_r = i;
		if (i != 0)
			fork_l = i - 1;
		data->philos[i].eat_count = 0;
		i++;
	}
	data->philos[0].fork_l = arg->num_philos - 1;
}

int	init_data(t_arg *arg, t_data *data)
{
	int	i;

	data->start_time = get_time;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * arg->num_philos);
	if (!data->philos)
		return (0);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg->num_philos);
	if (!data->forks)
	{
		free(data->philos);
		return (0);
	}
	init_philos(arg, data);
	i = 0;
	while (i < arg->num_philos)
		pthread_mutex_init(&(data->forks[i++]), NULL);
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->count), NULL);
	pthread_mutex_init(&(data->death), NULL);
}
