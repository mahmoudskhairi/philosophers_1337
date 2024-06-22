/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:52:26 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/22 15:27:56 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
#define PHILOSOFERS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define YELLOW "\x1B[33m"
#define GREEN "\x1B[32m"
#define WHITE "\x1B[37m"
#define BLUE "\x1B[34m"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"

typedef struct s_data
{
	size_t philos_nbr;
	size_t time_to_eat;
	size_t time_to_sleep;
	size_t time_to_die;
	size_t eat_times;
    size_t start_time;
    size_t is_died;
    size_t is_printed;
    // size_t start_time;
    pthread_mutex_t print;
    pthread_mutex_t death;
	// t_philo *to_philo;
	pthread_mutex_t *mutex;
	pthread_t *pths;
}   t_data;

typedef struct philo
{
    pthread_t pth;
	int index_philo;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
    // int last_eat;
	t_data *data;
    size_t last_time2eat;
}   t_philo;


int	ft_atoi(char *str);
void	add_philosofers(t_data *data, t_philo *philo);
void print_line(t_philo *philo, char *str, char c);
void	eating(t_philo *philo);
void sleeping (t_philo *philo);
void thinking (t_philo *philo);
size_t	get_currect_time(void);
void	ft_usleep(int time_to_sleep);
void    join_threads(t_data *data, t_philo *philo);
void  check_death(t_philo *philo);
// int  check_death(t_philo *philo);
int    get_death(t_philo *philo);
void    set_death(t_philo *philo);

#endif