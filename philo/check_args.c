/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:53:53 by mskhairi          #+#    #+#             */
/*   Updated: 2024/07/25 14:01:31 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	is_number(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_negative(t_data *data)
{
	if (data->philos_nbr <= 0 || data->time_to_eat < 0 || data->time_to_die < 0
		|| data->time_to_sleep < 0)
		return (0);
	return (1);
}

int	check_args(t_data *data, t_philo *philo, int ac, char *av[])
{
	int	i;

	i = 1;
	(void)data;
	(void)philo;
	while (i < ac)
	{
		if (!is_number(av[i]))
			return (0);
		i++;
	}
	if (!is_negative(data))
		return (0);
	if (ac == 6 && data->eat_times <= 0)
	{
		return (0);
	}
	if (data->philos_nbr > 200 || data->time_to_eat < 60
		|| data->time_to_die < 60 || data->time_to_sleep < 60)
		return (0);
	return (1);
}
