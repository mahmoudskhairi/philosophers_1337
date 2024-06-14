/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:54:23 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/07 12:59:04 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if (pid == -1)
    {
        printf("Error\n");
        return (1);
    }
    if (pid == 0)
    {
        printf("child proccess is created\n");
    }
    printf("pid process is [%d]\n",getpid());
    if (pid != 0)
    {
        wait(NULL);
    }
    return (0);
}