/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philosofers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:34:58 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/27 19:19:47 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	add_philosofers(t_data *data, t_philo *philo)
{
	size_t	i;

	i = 0;
	data->mutex = malloc(data->philos_nbr * sizeof(pthread_mutex_t));
	while (i < data->philos_nbr)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			printf("error initing mutex\n");
		philo[i].data = data;
		philo[i].index_philo = i + 1;
		philo[i].right_fork = &data->mutex[i];
		if (i == data->philos_nbr - 1)
			philo[i].left_fork = &data->mutex[0];
		else
			philo[i].left_fork = &data->mutex[i + 1];
		i++;
	}
}
