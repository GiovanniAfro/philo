/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:29:34 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/26 15:06:45 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time  ft_init_info(char **av)
{
    t_time  info;

    info.number_of_philos =ft_atoi(av[1]);
    info.time_to_die = ft_atoi(av[2]);
    info.time_to_eat = ft_atoi(av[3]);
    info.time_to_sleep = ft_atoi(av[4]);
    if(av[5])
        info.meals = ft_atoi(av[5]);
    else
        info.meals = -1;
    //inizializzare le info
}

int main(int ac, char **av)
{
    t_time  *info;
    t_philo *philos;
    

    if (ac < 5 || ac >6)
    {
        if (ft_controller_error_intput(ac, av))
            return(1);
        info = ft_init_info(av);
    }
    return (0);
}
