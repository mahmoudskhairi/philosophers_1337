/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:52:26 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/16 16:55:11 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
#define PHILOSOFERS_H

#include <pthread.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>//


typedef struct s_data
{
	int philos_nbr;
	int timeof_eating;
	int timeof_sleeping;
	int timeof_dying;
	int eat_times;
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
void    join_philos(t_data *data, t_philo *philo);

#endif