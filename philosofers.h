/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:52:26 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/11 13:30:23 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
#define PHILOSOFERS_H

#include <pthread.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct philo
{
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	pthread_mutex_t print;
	int index_philo;
    struct philo *next;
}   t_philo;

typedef struct 
{
	int philos_nbr;
	int timeof_eating;
	int timeof_sleeping;
	int timeof_dying;
	int eat_times;
	t_philo *to_philo;
	pthread_mutex_t *mutex;

}   t_data;

void	add_philosofers(t_data *data);
#endif