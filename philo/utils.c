/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:17:00 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/22 21:58:29 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((*(str1 + i) == *(str2 + i)) && *(str1 + i) && *(str2 + i)
		&& (i + 1) < n)
		i++;
	return (*(str1 + i) - *(str2 + i));
}

void	pthread_mutex_init_s(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
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
		i++;
	}
	i = 0;
	while (i < arg->num_philos)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->death));
	free(philos);
	free(data->forks);
	data->forks = NULL;
}

void	opt_timer(int time_arg)
{
	unsigned long long	start_time;

	start_time = get_time();
	while(get_time() < start_time + time_arg)
		usleep(1);
}
