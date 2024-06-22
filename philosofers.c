/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:33 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/22 16:00:14 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void  check_death(t_philo *philo)
{
    size_t i;

    while(1)
    {
        i = 0;
        while(i < philo[i].data->philos_nbr)
        {
            if (get_currect_time() - philo[i].last_time2eat >= philo[i].data->time_to_die)
            {
                pthread_mutex_lock(&philo[i].data->print);
                printf("%zu %d " RED "died\n" RESET, get_currect_time()
                    - philo[i].data->start_time, philo[i].index_philo);
                set_death(philo);
                pthread_mutex_unlock(&philo[i].data->print);
                return;
            }
            i++;
        }
    }
}

// void  check_death(t_philo *philo)
// {
    
//     // pthread_mutex_lock(&philo->data->death);
//     if (get_currect_time() - philo->last_time2eat >= philo->data->time_to_die && get_death(philo))
//     {
//         pthread_mutex_lock(&philo->data->print);
//         printf("%zu %d " RED "died\n" RESET, get_currect_time()
//             - philo->data->start_time, philo->index_philo);
//         set_death(philo);
//         pthread_mutex_unlock(&philo->data->print);
//     }
//     // pthread_mutex_unlock(&philo->data->death);
// }

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
        if (!get_death(philo))
            break;
    }
	return (NULL);
}

void	creat_threads(t_data *data, t_philo *philo)
{
	size_t	i;

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
        data.start_time = get_currect_time();
        data.is_died = 1;
		data.pths = malloc(data.philos_nbr * sizeof(pthread_t));
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
        check_death(philo);
		join_threads(&data, philo);
		pthread_mutex_destroy(&data.print);
		pthread_mutex_destroy(&data.death);
	}
	return (0);
}
