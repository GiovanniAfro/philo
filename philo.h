/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:29:21 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/20 17:29:19 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	size_t	philo;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	int	number_of_meals;
}		t_philo;

typedef struct	s_time
{
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
}	t_time;

int 	ft_controller_error_intput(int ac, char **av);
long	ft_time(void);
#endif