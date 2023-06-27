/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:17:15 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/27 12:03:08 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t   get_timestamp(void)
{
    struct timeval  start_time;

    gettimeofday(&end_time, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}