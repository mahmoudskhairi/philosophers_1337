/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:23:23 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/30 13:37:13 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	init_data(t_data *data, t_philo **philo, int ac, char *av[])
{
	data->philos_nbr = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->is_died = 0;
	*philo = malloc(data->philos_nbr * sizeof(t_philo));
	if (!*philo)
		return (0);
	if (ac == 6)
		data->eat_times = ft_atoi(av[5]);
	else
		data->eat_times = -1;
	return (1);
}
