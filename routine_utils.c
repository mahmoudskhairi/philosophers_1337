/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:48 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/22 15:07:39 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	print_line(t_philo *philo, char *str, char c)
{
    if (c == 'F' && get_death(philo))
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%zu %d " YELLOW "%s\n" RESET, get_currect_time()
				- philo->data->start_time, philo->index_philo, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (c == 'E' && get_death(philo))
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%zu %d " GREEN "%s\n" RESET, get_currect_time()
				- philo->data->start_time, philo->index_philo, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (c == 'S' && get_death(philo))
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%zu %d " BLUE "%s\n" RESET, get_currect_time()
				- philo->data->start_time, philo->index_philo, str);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	eating(t_philo *philo)
{
    if (get_death(philo))
    {
        pthread_mutex_lock(philo->right_fork);
        print_line(philo, "has taken a fork", 'F');
        pthread_mutex_lock(philo->left_fork);
        philo->last_time2eat = get_currect_time();
        print_line(philo, "has taken a fork", 'F');
        print_line(philo, "is eating", 'E');
        ft_usleep(philo->data->time_to_eat);
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
    }
}

int    get_death(t_philo *philo)
{
    int tmp;
    
    pthread_mutex_lock(&philo->data->death);
    tmp = philo->data->is_died;
    pthread_mutex_unlock(&philo->data->death);
    return (tmp);
}
void    set_death(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->death);
    philo->data->is_died = 0;
    pthread_mutex_unlock(&philo->data->death);
}

void	sleeping(t_philo *philo)
{
    if (get_death(philo))
    {
	    print_line(philo, "is sleeping", 'S');
    	ft_usleep(philo->data->time_to_sleep);
    }
}

void	thinking(t_philo *philo)
{
    if (get_death(philo))
    {
        pthread_mutex_lock(&philo->data->print);
        printf("%zu %d " WHITE "is thinking\n" RESET, get_currect_time()
                - philo->data->start_time, philo->index_philo);
        pthread_mutex_unlock(&philo->data->print);
    }
}
