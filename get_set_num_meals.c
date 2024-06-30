/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_num_meals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:31:12 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/30 17:35:12 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	set_num_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->data->count_meals++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
}

int	get_num_meals(t_philo *philo)
{
	int count;

	pthread_mutex_lock(&philo->data->meal_mutex);
	count = philo->data->count_meals;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (count);
}
