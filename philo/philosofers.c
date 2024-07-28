/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:33 by mskhairi          #+#    #+#             */
/*   Updated: 2024/07/28 11:57:08 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	*routine(void *philo_)
{
	t_philo	*philo;

	philo = (t_philo *)philo_;
	if (philo->data->philos_nbr == 1)
	{
		print_line(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die, philo);
		return (NULL);
	}
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
	int	i;

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

	if (ac == 5 || ac == 6)
	{
		if (!init_data(&data, &philo, ac, av))
			return (1);
		if (!check_args(&data, philo, ac, av) || !init_mutex(&data, philo))
		{
			free_all(&data, philo);
			printf("Error\n");
			return (1);
		}
		init_philosofers(&data, philo);
		creat_threads(&data, philo);
		check_death(&data, philo);
		join_threads(&data, philo);
		destroy_mutex(&data, philo);
		free_all(&data, philo);
	}
	else
		printf("Invalid arguments\n");
	return (0);
}
