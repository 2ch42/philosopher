/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:04:51 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/26 15:36:26 by changhyl         ###   ########.fr       */
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

typedef struct s_data
{
	unsigned long long	start_time;
	t_arg				*arg;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		death;
	pthread_mutex_t		eat;
	int					die;
	int					done_phil;
}	t_data;

typedef struct t_philo
{
	pthread_t			thread;
	t_data				*data;
	int					num;
	int					fork_l;
	int					fork_r;
	int					eat_count;
	unsigned long long	last_meal;
	pthread_mutex_t		time;
}	t_philo;

int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
unsigned long long	get_time(void);
void				opt_timer(int time_arg);
int					init_arg(t_arg *arg, int argc, char *argv[]);
int					init_data(t_arg *arg, t_data *data);
void				free_clear(t_arg *arg, t_data *data, t_philo *philos);
void				pthread_mutex_init_s(pthread_mutex_t *mutex);
void				philo_print(t_philo *philo, char *status);
void				pick_fork(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				run_philos(t_philo *philo);

#endif
