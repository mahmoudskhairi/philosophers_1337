/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:17:01 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/29 18:20:16 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	check_death(t_data *data, t_philo *philo)
{
	size_t	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo[i].eat_mutex);
		if (get_currect_time() - philo[i].last_time2eat >= data->time_to_die)
		{
			set_death(philo);
			pthread_mutex_lock(&data->print);
			printf("%zu %d died\n", get_currect_time()
					- data->start_time, philo[i].index_philo);
			pthread_mutex_unlock(&data->print);
			pthread_mutex_unlock(&philo[i].eat_mutex);
			return ;
		}
        if (data->nbr_of_meals == data->philos_nbr * data->eat_times)
		{
			pthread_mutex_unlock(&philo[i].eat_mutex);
            set_death(&philo[i]);
            printf( RED "end of eating !!" RESET "\n");
			return ;
		}
		pthread_mutex_unlock(&philo[i].eat_mutex);
		i++;
		if (i == data->philos_nbr)
			i = 0;
		usleep(200);
	}
}