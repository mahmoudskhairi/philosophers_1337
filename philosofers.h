/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:52:26 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/20 16:05:09 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
#define PHILOSOFERS_H

#include <pthread.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>//
#include <sys/time.h>


typedef struct s_data
{
	int philos_nbr;
	int time_to_eat;
	int time_to_sleep;
	int time_to_die;
	int eat_times;
    size_t start_time;
    pthread_mutex_t print;
	// t_philo *to_philo;
	pthread_mutex_t *mutex;
	pthread_t *pths;
}   t_data;

typedef struct philo
{
    int last_eat;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
    pthread_t pth;
	int index_philo;
	t_data *data;
}   t_philo;

void	add_philosofers(t_data *data, t_philo *philo);
void    join_threads(t_data *data, t_philo *philo);

#endif