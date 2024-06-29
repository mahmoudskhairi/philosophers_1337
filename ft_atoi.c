/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:26:16 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/29 10:19:18 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	ft_atoi(char *str)
{
	long long	tot;
	int			sign;

	sign = 1;
	tot = 0;
	if (!str || !*str)
	{
		return (0);
	}
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		tot = (tot * 10) + (*str - 48);
		str++;
	}
	return (sign * tot);
}
