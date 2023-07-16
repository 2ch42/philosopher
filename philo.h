/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:10:32 by changhyl          #+#    #+#             */
/*   Updated: 2023/07/16 21:05:43 by changhyl         ###   ########.fr       */
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
	pthread_t		thread;
	int				num;
	int				fork_l;
	int				*fork_r;
	int				eat_count;
}	t_philo;

typedef struct	s_data
{
	int					errno;
	int					die;
	unsigned long long	start_time;
	t_philo				*philos;
	pthread_mutex_t		forks;
	pthread_mutex_t		print;
	pthread_mutex_t		count;
	pthread_mutex_t		death;
}	t_data;

int	ft_atoi(const char *str);
int	init_arg(t_arg *arg, int argc, char *argv[]);

#endif
