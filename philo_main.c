/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:46:10 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/17 20:58:58 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	*arg;
	t_data	*data;
	int		arg_val;

	if (argc != 5 && argc != 6)
		return (0);
	arg_val = init_arg(arg, argc, argv);
	if (arg_val == -1)
	{
		write(2, "Error!\n", 7);
		if (arg)
			free(arg);
		return (0);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		free(arg);
		return (0);
	}
	run_philo(arg, data);
	free_clear(arg, data);
	return (0);
}
