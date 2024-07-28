/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:28:46 by mskhairi          #+#    #+#             */
/*   Updated: 2024/07/28 11:54:26 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	get_death(t_philo *philo)
{
	int	tmp;

	pthread_mutex_lock(&philo->data->death);
	tmp = philo->data->is_died;
	pthread_mutex_unlock(&philo->data->death);
	return (tmp);
}

void	set_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death);
	philo->data->is_died = 1;
	pthread_mutex_unlock(&philo->data->death);
}
