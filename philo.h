/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:29:21 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/26 15:04:13 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_time
{
	size_t	number_of_philos;
	int 	time_to_die;
	int 	time_to_eat;
	int 	time_to_sleep;
	int		meals;
}	t_time;

typedef struct	s_philo
{
	size_t			philo_id;
	t_time			*time;
	pthread_t		philo;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
}	t_philo;

int	ft_controller_error_intput(int ac, char **av);

#endif