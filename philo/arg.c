/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:58:03 by changhyl          #+#    #+#             */
/*   Updated: 2023/08/19 12:20:39 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	check_str(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (ft_isdigit(*(str + i)) == 0)
			return (0);
		i++;
	}
	if (i > 8)
		return (0);
	return (1);
}

int	init_arg(t_arg *arg, int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
		return (0);
	if (!(check_str(argv[1]) && check_str(argv[2]) && check_str(argv[3])
			&& check_str(argv[4])))
		return (0);
	if (argc == 6 && check_str(argv[5]) == 0)
		return (0);
	if (argc == 6 && check_str(argv[5] == 1))
		arg->num_must = ft_atoi(argv[5]);
	if (argc == 5)
		arg->num_must = -1;
	arg->num_philos = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	return (1);
}
