/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:52:26 by mskhairi          #+#    #+#             */
/*   Updated: 2024/07/20 12:00:32 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define YELLOW "\x1B[33m"
# define GREEN "\x1B[32m"
# define WHITE "\x1B[37m"
# define BLUE "\x1B[34m"
# define RED "\x1B[31m"
# define RESET "\x1B[0m"

typedef struct s_data
{
	int				philos_nbr;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				eat_times;
	size_t			start_time;
	size_t			is_died;
	size_t			meals;
	size_t			count_meals;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*mutex;
	pthread_t		*pths;
}					t_data;

typedef struct philo
{
	pthread_t		pth;
	int				index_philo;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	eat_mutex;
	t_data			*data;
	int				last_time2eat;
}					t_philo;

int					ft_atoi(char *str);
void				init_philosofers(t_data *data, t_philo *philo);
void				print_line(t_philo *philo, char *str);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
int					get_currect_time(void);
void				ft_usleep(int time_to_sleep, t_philo *philo);
void				join_threads(t_data *data, t_philo *philo);
void				check_death(t_data *data, t_philo *philo);
int					get_death(t_philo *philo);
void				set_death(t_philo *philo);
int					init_data(t_data *data, t_philo **philo, int ac,
						char *av[]);
int					init_mutex(t_data *data, t_philo *philo);
void				free_all(t_data *data, t_philo *philo);
void				destroy_mutex(t_data *data, t_philo *philo);
void				check_death(t_data *data, t_philo *philo);
int					check_args(t_data *data, t_philo *philo, int ac,
						char *av[]);
void				set_death(t_philo *philo);
int					get_death(t_philo *philo);
void				set_num_meals(t_philo *philo);
int					get_num_meals(t_philo *philo);

#endif