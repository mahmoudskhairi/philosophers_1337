/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philosofers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:38:46 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/16 11:02:06 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

// void*   philo_eating(t_data *data)
// {
//     pthread_mutex_lock(&data->to_philo->print);
//     // printf("timestamp_in_ms %d has taken a fork\n", count++);
//     pthread_mutex_unlock(&data->to_philo->print);
// }
void *routine(void *ptr_data)
{
    t_data *data = (t_data *)ptr_data;
    t_philo philo;
    philo.right_fork = &data->mutex[0];
    philo.left_fork = &data->mutex[0];
    // philo_taking_fork(data_ptr);
    // philo_eating(data_ptr);
    // philo_sleeping();
    // philo_thinking();
    // philo_died();
	return (NULL);
}

void	add_philosofers(t_data *data)
{
	pthread_t t[data->philos_nbr];
    pthread_mutex_t mutex[data->philos_nbr];
	int i;

	i = 0;
    data->mutex = mutex;
	while(i < data->philos_nbr)
	{
	    pthread_mutex_init(mutex + i, NULL);
		pthread_create(&t[i], NULL, routine, data);
		i++;
	}
	i = 0;
	while(i < data->philos_nbr)
	{
		pthread_join(t[i], NULL);
    	pthread_mutex_destroy(mutex + i);
		i++;
	}
	// ft_printf("%d\n", data->mails);
}