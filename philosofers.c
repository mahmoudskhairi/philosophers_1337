/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:33 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/10 18:00:43 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int main(int ac, char *av[])
{
	t_data	data;

	if (ac == 4 || ac == 5)
	{
		data.philos_nbr = ft_atoi(av[1]);
		data.timeof_dying = ft_atoi(av[2]);
		data.timeof_sleeping = ft_atoi(av[3]);
		data.timeof_eating = ft_atoi(av[4]);
		data.eat_times = ft_atoi(av[5]);
		add_philosofers(&data);
		// take_forks();
		// eating_time();
		// sleeping_time();
        
	}
}
