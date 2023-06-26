/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:17:15 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/26 15:06:46 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long   ft_time(void)
{
    struct timeval  start_time;
    struct timeval  end_time;
    long    milliseconds;

    gettimeofday(&start_time, NULL);
    gettimeofday(&end_time, NULL);
    milliseconds = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
    return (milliseconds);
}