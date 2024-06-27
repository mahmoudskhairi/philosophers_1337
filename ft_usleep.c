/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:36:41 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/27 19:31:54 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

size_t	get_currect_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(int time_to_sleep)
{
	size_t	current_time;
	size_t	expected_time;

	current_time = get_currect_time();
    expected_time = current_time + time_to_sleep;
    while(get_currect_time() < expected_time)
        usleep(200);
	// while (get_currect_time() <= current_time + time_to_sleep)
    // {
    // }
}

// void	ft_usleep(int time_to_sleep)
// {
// 	unsigned long	start_time;
// 	unsigned long	expected_time;

// 	start_time = get_currect_time();
// 	expected_time = start_time + time_to_sleep;
// 	while (get_currect_time() < expected_time)
// 		usleep(200);
// }
