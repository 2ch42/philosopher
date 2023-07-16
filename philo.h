/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:10:32 by changhyl          #+#    #+#             */
/*   Updated: 2023/07/15 22:40:30 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct	s_arg
{
	int	num_phil;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
}	t_arg;

typedef struct	s_philo
{
	pthread_t	thread;
	int	count;
}	t_philo;

typedef struct	s_data
{
	pthread_mutex_t	*print;
	pthread_mutex_t *fork;
	pthread_mutex_t	*count;
	pthread_mutex_t	*die;
}	t_data;

int	ft_atoi(const char *str);
int	init_arg(t_arg *arg, int argc, char *argv[]);

#endif
