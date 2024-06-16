/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:33 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/16 16:57:35 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void    eating(t_philo *philo)
{
    printf("===========HHHHHHHHHHHHH===========\n");
    printf(" ADDDDDDDDRESSSSSSS  : %p    \n", &philo->data->print);
    pthread_mutex_lock(&philo->data->print);
//     pthread_mutex_lock(philo->right_fork);
   // printf("philo nbr %d taken a right fork\n", philo->index_philo);
//     pthread_mutex_unlock(philo->right_fork);
//     pthread_mutex_lock(philo->left_fork);
//     printf("philo nbr %d taken a left fork\n", philo->index_philo);
//     usleep(philo->data->timeof_eating);
//     printf("philo nbr %d is eating\n", philo->index_philo);
    pthread_mutex_unlock(&philo->data->print);
}

void *routine(void *philo_)
{
    t_philo *philo;
    philo = (t_philo *)philo_;
    // if (philo->index_philo % 2 == 0)
    // {
    //     printf("hello\n");
    //     usleep(philo->data->timeof_sleeping);
    // }
    eating(philo);
    return (NULL);
}

void creat_threads(t_data *data ,t_philo *philo)
{
    int i;

    i = 0;
    while (i < data->philos_nbr)
    {
        pthread_create(&philo[i].pth, NULL, &routine, (void *)&philo[i]);
        i++;
    }
}
// void    init_philo(t_data *data, t_philo *philo, int i)
// {

// }
void add_philosofers(t_data *data, t_philo *philo)
{
	int i;
    i = 0;
    // printf("nbr = %d\n", data->philos_nbr);
    data->mutex = malloc(data->philos_nbr * sizeof(pthread_mutex_t));
    // printf("hahowa malocca hena\n");
	while (i < data->philos_nbr)
	{
        if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
            printf("failat\n");
		philo[i].index_philo = i + 1;
        //philo[i].pth = data->pths[i];
        philo[i].right_fork = &data->mutex[i];
        // printf("right fork %d\n", i + 1);
        if (i == data->philos_nbr - 1)
            philo[i].left_fork = &data->mutex[0];
        else
            philo[i].left_fork = &data->mutex[i + 1];
		i++;
	}
    // printf("philo n 1 = %d\n", philo[1].index_philo);
    // printf("sala\n");
}

int main(int ac, char *av[])
{
	t_data	data;
    t_philo *philo;

	if (ac == 4 || ac == 5)
	{
        data.pths = malloc(data.philos_nbr * sizeof(pthread_t));
        philo = malloc(data.philos_nbr * sizeof(t_philo));
		data.philos_nbr = ft_atoi(av[1]);
		data.timeof_dying = ft_atoi(av[2]);
		data.timeof_sleeping = ft_atoi(av[3]);
		data.timeof_eating = ft_atoi(av[4]);
		data.eat_times = ft_atoi(av[5]);
        if (pthread_mutex_init(&data.print, NULL))
            return(1);
		add_philosofers(&data, philo);
        creat_threads(&data, philo);
        join_philos(&data, philo);
		// add_philosofers(&data);
		// take_forks();
		// eating_time();
		// sleeping_time();
        pthread_mutex_destroy(&data.print);
	}
    return (0);
}

void    join_philos(t_data *data, t_philo *philo)
{
    int i;

    i = 0;
    while (i < data->philos_nbr)
    {
        pthread_join(philo[i].pth, NULL);
        // pthread_mutex_destroy(philo[i].right_fork);
        i++;
    }
}
