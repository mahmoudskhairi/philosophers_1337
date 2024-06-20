/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:33 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/20 16:36:56 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

// void    eating(t_philo *philo)
// {
//     pthread_mutex_lock(&philo->data->print);
//     //     pthread_mutex_lock(philo->right_fork);
//     //     printf("philo nbr %d taken a right fork\n", philo->index_philo);
//     //     pthread_mutex_unlock(philo->right_fork);
//     //     pthread_mutex_lock(philo->left_fork);
//     //     printf("philo nbr %d taken a left fork\n", philo->index_philo);
//     //     usleep(philo->data->timeof_eating);
//     //     printf("philo nbr %d is eating\n", philo->index_philo);
//     pthread_mutex_unlock(&philo->data->print);
// }
size_t	get_currect_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(int time_to_sleep)
{
	size_t	current_time;

	current_time = get_currect_time();
	while (get_currect_time() < current_time + time_to_sleep)
		;
}

void print_line(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->data->print);
    printf("%zu %d %s\n", get_currect_time() - philo->data->start_time, philo->index_philo, str);
    pthread_mutex_unlock(&philo->data->print);
}
void	eating(t_philo *philo)
{
    pthread_mutex_lock(philo->right_fork);
    print_line(philo, "is taken a right fork");
    pthread_mutex_lock(philo->left_fork);
    print_line(philo, "is taken a left fork");
    print_line(philo, "is eating");
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
} 

void sleeping (t_philo *philo)
{   
    print_line(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep);
}

void thinking(t_philo *philo)
{   
    print_line(philo, "is thinking");
}

void	*routine(void *philo_)
{
	t_philo	*philo;

    philo = (t_philo *)philo_;
    if (philo->index_philo % 2 == 0)
        sleeping(philo);
    while (1)
    {
        thinking(philo);
        eating(philo);
        sleeping(philo);
    }
	return (NULL);
}

void	creat_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_create(&philo[i].pth, NULL, &routine, (void *)&philo[i]);
		i++;
	}
}

void	add_philosofers(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->mutex = malloc(data->philos_nbr * sizeof(pthread_mutex_t));
	while (i < data->philos_nbr)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
			printf("error initing mutex\n");
		philo[i].data = data;
		philo[i].index_philo = i;
		philo[i].right_fork = &data->mutex[i];
		if (i == data->philos_nbr - 1)
			philo[i].left_fork = &data->mutex[0];
		else
			philo[i].left_fork = &data->mutex[i + 1];
		// printf("index of philo %d\n", philo[i].index_philo);
		i++;
	}
}
void	join_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philos_nbr)
	{
		pthread_join(philo[i].pth, NULL);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_data	data;
	t_philo	*philo;

	if (ac == 4 || ac == 5)
	{
		data.pths = malloc(data.philos_nbr * sizeof(pthread_t));
		philo = malloc(data.philos_nbr * sizeof(t_philo));
		data.philos_nbr = ft_atoi(av[1]);
		data.time_to_die = ft_atoi(av[2]);
		data.time_to_eat = ft_atoi(av[3]);
		data.time_to_sleep = ft_atoi(av[4]);
		data.eat_times = ft_atoi(av[5]);
        data.start_time = get_currect_time();
		if (pthread_mutex_init(&data.print, NULL) != 0)
		{
			printf("error initing print mutex\n");
			return (1);
		}
		
		add_philosofers(&data, philo);
		creat_threads(&data, philo);
		join_threads(&data, philo);
		pthread_mutex_destroy(&data.print);
	}
	return (0);
}
