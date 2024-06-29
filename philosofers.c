/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:33 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/29 18:20:29 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	*routine(void *philo_)
{
	t_philo	*philo;

	philo = (t_philo *)philo_;
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
		philo[i].last_time2eat = data->start_time;
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

// void    check_nbr_meals(t_data *data, t_philo *philo)
// {
//     size_t i;

//     i = 0;
//     while (1)
//     {
// 		if (data->nbr_of_meals == data->philos_nbr * data->eat_times)
// 		{
// 			pthread_mutex_unlock(&philo[i].eat_mutex);
//             set_death(&philo[i]);
//             printf( RED "end of eating !!" RESET "\n");
// 			return ;
// 		}
// 		i++;
// 		if (i == data->philos_nbr)
// 			i = 0;
//     }
// }

void    ll()
{
    system("leaks philo");
}

int	main(int ac, char *av[])
{
	t_data	data;
	t_philo	*philo;

    // atexit(ll);
	if (ac == 5 || ac == 6)
	{
		init_data(&data, &philo, ac, av);
		if (init_mutex(&data, philo))
			return (1);
		init_philosofers(&data, philo);
		creat_threads(&data, philo);
		check_death(&data, philo);
        // check_nbr_meals(&data, philo);
		join_threads(&data, philo);
		destroy_mutex(&data, philo);
		free_all(&data, philo);
	}
	return (0);
}
