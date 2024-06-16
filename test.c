/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:54:23 by mskhairi          #+#    #+#             */
/*   Updated: 2024/06/15 16:17:24 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count ;
pthread_mutex_t mutex;
void *routine()
{
    pthread_mutex_lock(&mutex);
    count++;
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

int main()
{
    pthread_t th[10000];
    int i = 0;
    while (i < 10000)
    {
        pthread_create(&th[i],NULL, &routine, NULL);
        i++;
    }
    i = 0;
    while (i < 10000)
    {
        pthread_join(th[i],NULL);
        i++;
    }
    printf("count == %d\n", count);
    return (0);
}