/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:39:14 by changhyl          #+#    #+#             */
/*   Updated: 2023/07/16 00:56:08 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	run_philo(t_arg *arg)
{
	int	i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * arg->phil_num);
	while (i < arg->phil_num)
	{
		pthread_create(philos[0].thread, NULL, , );
		i++;
	}
}
