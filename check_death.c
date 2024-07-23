/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:17:01 by mskhairi          #+#    #+#             */
/*   Updated: 2024/07/23 07:56:01 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	check_meals(t_data *data, t_philo *philo, int i)
{
	if (get_num_meals(philo) >= data->philos_nbr * data->eat_times)
	{
		set_death(philo);
		pthread_mutex_unlock(&philo[i].eat_mutex);
		return (1);
	}
	return (0);
}

void	check_death(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo[i].eat_mutex);
		if (get_currect_time() - philo[i].last_time2eat >= data->time_to_die)
		{
			set_death(philo);
			pthread_mutex_lock(&data->print);
			printf("%zu %d died\n", get_currect_time() - data->start_time,
				philo[i].index_philo);
			pthread_mutex_unlock(&data->print);
			pthread_mutex_unlock(&philo[i].eat_mutex);
			return ;
		}
		if (data->eat_times != -1)
			if (check_meals(data, philo, i))
				return ;
		pthread_mutex_unlock(&philo[i].eat_mutex);
		i++;
		if (i == data->philos_nbr)
			i = 0;
		usleep(200);
	}
}
