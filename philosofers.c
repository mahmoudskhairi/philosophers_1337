/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:33 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/28 19:56:44 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void  check_death(t_data *data, t_philo *philo)
{
    size_t i;

    i = 0;
    (void)philo;
    while(1)
    {
        pthread_mutex_lock(&philo[i].eat_mutex);
        if (get_currect_time() - philo[i].last_time2eat >= data->time_to_die)
        {
            set_death(philo);
            pthread_mutex_lock(&data->print);
            printf("%zu %d " RED "died\n" RESET, get_currect_time()
                - data->start_time, philo[i].index_philo);
            pthread_mutex_unlock(&data->print);
            pthread_mutex_unlock(&philo[i].eat_mutex);
            return;
        }
        pthread_mutex_unlock(&philo[i].eat_mutex);
        i++;
        if (i == data->philos_nbr)
            i = 0;
        usleep(500);
    }
}

void	*routine(void *philo_)
{
	t_philo	*philo;

    philo = (t_philo *) philo_;
    if (philo->index_philo % 2 == 0)
        sleeping(philo); 
    while (!get_death(philo))
    {   
        thinking(philo);
        eating(philo);
        sleeping(philo);
    }
	return (NULL);
}

void	creat_threads(t_data *data, t_philo *philo)
{
	size_t	i;

	i = 0;
    data->start_time = get_currect_time();
	while (i < data->philos_nbr)
	{
        if (pthread_mutex_init(&philo[i].eat_mutex, NULL) != 0)
		{
			printf("error initing print mutex\n");
		}
        philo[i].last_time2eat = data->start_time;
		i++;
	}
    i = 0;
	while (i < data->philos_nbr)
	{
		pthread_create(&philo[i].pth, NULL, &routine, (void *)&philo[i]);
		i++;
	}
}

void	join_threads(t_data *data, t_philo *philo)
{
	size_t	i;

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
		data.philos_nbr = ft_atoi(av[1]);
		data.time_to_die = ft_atoi(av[2]);
		data.time_to_eat = ft_atoi(av[3]);
		data.time_to_sleep = ft_atoi(av[4]);
		data.eat_times = ft_atoi(av[5]);
        data.is_died = 0;
		// data.pths = malloc(data.philos_nbr * sizeof(pthread_t));
		philo = malloc(data.philos_nbr * sizeof(t_philo));
		if (pthread_mutex_init(&data.print, NULL) != 0)
		{
			printf("error initing print mutex\n");
			return (1);
		}
		if (pthread_mutex_init(&data.death, NULL) != 0)
		{
			printf("error initing print mutex\n");
			return (1);
		}
		add_philosofers(&data, philo);
		creat_threads(&data, philo);
        check_death(&data, philo);
		join_threads(&data, philo);
		pthread_mutex_destroy(&data.print);
		pthread_mutex_destroy(&data.death);
		// pthread_mutex_destroy(&ph.eat_mutex);
	}
	return (0);
}
