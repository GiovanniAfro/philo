/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:29:21 by gcavanna          #+#    #+#             */
/*   Updated: 2023/07/03 11:47:26 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_philosopher_state
{
	STATE_THINK,
	STATE_EAT,
	STATE_SLEEP,
	STATE_DEAD
}	t_philosopher_state;

typedef struct s_philosopher
{
	size_t				id;
	pthread_t			thread;
	time_t				last_meal;
	t_philosopher_state	state;
	int					loop;
}	t_philosopher;

typedef struct s_global
{
	long			since_start;
	size_t			n_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				n_loop;
	bool			someone_died;
	t_philosopher	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	philo_mutex;
}	t_global;

#endif
