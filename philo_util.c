/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:40:52 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/17 19:39:17 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>
#include "philo.h"

void	free_clear(t_arg *arg, t_data *data)
{
	int	i;

	i = 0;
	while (i < arg->phil_num)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&(data->forks));
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->count));
	pthread_mutex_destroy(&(data->death));
	free(arg);
	free(data);
	arg = NULL;
	data = NULL;
}

unsigned long long	get_time(void)
{
	struct	timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}
