/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:29:46 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/17 20:16:24 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

void	init_fork(t_arg *arg, t_data *data)
{
	int	i;

	i = 0;
	while (i < arg->phil_num)
	{
		data->philos[i].fork_l = 0;
		if (i != arg->phil_num - 1)
			data->philos[i].fork_r = &(data->philos[i + 1].fork_l);
		i++;
	}
	data->philos[arg->phil_num - 1].fork_r = &(data->philos[0].fork_l);
}

void	init_data(t_arg *arg, t_data *data)
{
	int	i;

	data->errno = 0;
	data->start_time = get_time;
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->forks), NULL);
	pthread_mutex_init(&(data->count), NULL);
	pthread_mutex_init(&(data->death), NULL);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * arg->num_phil);
	if (!data->philos)
	{
		data->errno = -1;
		return ;
	}
	init_fork(arg, data);
	i = 0;
	while (i++ < arg->phil_num)
	{
		data->philos[i].num = i + 1;
		data->die = 0;
		pthread_create(data->philos[i].thread, NULL, ~, ~);
	}
}

void	run_philo(t_arg *arg, t_data *data)
{
	init_data(arg, data);
	if (data->errno != 0)
		return ;
	free_clear(arg, data);
}
