/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:48 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/21 20:56:57 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void print_line(t_philo *philo, char *str, char c)
{
	if (c == 'T')
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%zu %d " WHITE "%s\n" RESET, get_currect_time() - philo->data->start_time, philo->index_philo, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (c == 'F')
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%zu %d " YELLOW  "%s\n" RESET, get_currect_time() - philo->data->start_time, philo->index_philo, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (c == 'E')
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%zu %d " GREEN "%s\n" RESET, get_currect_time() - philo->data->start_time, philo->index_philo, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (c == 'S')
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%zu %d " BLUE "%s\n" RESET, get_currect_time() - philo->data->start_time, philo->index_philo, str);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	eating(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print_line(philo, "has taken a fork", 'F');
    pthread_mutex_lock(philo->left_fork);
    print_line(philo, "has taken a fork", 'F');
    print_line(philo, "is eating", 'E');
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
} 

void sleeping (t_philo *philo)
{   
    print_line(philo, "is sleeping", 'S');
    ft_usleep(philo->data->time_to_sleep);
}

void thinking(t_philo *philo)
{   
    print_line(philo, "is thinking", 'T');
}
