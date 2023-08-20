/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:48:37 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/19 12:19:37 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_data	data;

	if (!init_arg(&arg, argc, argv))
	{
		write(2, "Argument Error\n", 15);
		return (0);
	}
	if (!init_data(&arg, &data))
	{
		write(2, "Error occured while initializing\n". 33);
		return (0);
	}
	run_philo(arg, data);
	return (0);
}
