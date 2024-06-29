/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:48 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/29 18:22:03 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	print_line(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	if (!get_death(philo))
	{
		printf("%zu %d %s\n", get_currect_time() - philo->data->start_time,
			philo->index_philo, str);
	}
	pthread_mutex_unlock(&philo->data->print);
}

void	eating(t_philo *philo)
{
	if (!get_death(philo))
	{
		pthread_mutex_lock(philo->right_fork);
		print_line(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_line(philo, "has taken a fork");
		print_line(philo, "is eating");
		pthread_mutex_lock(&philo->eat_mutex);
		if (get_currect_time()
			- philo->last_time2eat < philo->data->time_to_die)
			philo->last_time2eat = get_currect_time();
		pthread_mutex_unlock(&philo->eat_mutex);
		ft_usleep(philo->data->time_to_eat, philo);
        philo->data->nbr_of_meals++;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

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

void	sleeping(t_philo *philo)
{
	if (!get_death(philo))
	{
		print_line(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo);
	}
}

void	thinking(t_philo *philo)
{
	if (!get_death(philo))
		print_line(philo, "is thinking");
}
