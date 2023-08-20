/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:17:00 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/20 03:10:01 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

unsigned long long	get_time(void)
{
	struct	timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void	free_clear(t_arg *arg, t_data *data)
{
	int	i;

	i = 0;
	while (i < arg->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(print);
	pthread_mutex_destroy(count);
	pthread_mutex_destroy(death);
	free(data->philos);
	free(data->forks);
	data->forks = NULL;
}
