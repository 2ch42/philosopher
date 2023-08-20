/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:04:51 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/19 13:28:12 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef FORK
#  define FORK "has taken a fork"
# endif
# ifndef EATING
#  define EATING "is eating"
# endif
# ifndef SLEEPING
#  define SLEEPING "is sleeping"
# endif
# ifndef THINKING
#  define THINKING "is thinking"
# endif
# ifndef DIED
#  define DIED "died"
# endif

# include <pthread.h>

typedef struct s_arg
{
	int	num_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must;
}	t_arg;

typedef struct s_philo
{
	pthread_t	thread;
	int		num;
	int		fork_l;
	int		fork_r;
	int		eat_count;
}	t_philo;

typedef struct s_data
{
	unsigned long long	start_time;
	t_philo			*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		count;
	pthread_mutex_t		death;
}	t_data;

int			ft_atoi(const char *str);
unsigned long long	get_time(void);
int			init_arg(t_arg *arg, int argc, char *argv[]);
int			init_data(t_arg *arg, t_data *data);

#endif
