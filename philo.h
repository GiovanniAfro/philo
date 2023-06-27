/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:29:21 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/27 18:08:11 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_philosopher_state
{
	STATE_THINK,
	STATE_EAT,
	STATE_SLEEP,
	STATE_DEAD
}						t_philospher_state;

typedef struct			s_fork;
{
	pthread_mutex_t mutex;
}
t_fork;

typedef struct s_philosopher
{
	int					id;
	time_t last meal;
	int					loop;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread;
	t_philosopher_state	state;
}						t_philosopher;

typedef struct s_global
{
	size_t				n_philo;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int					n_loop;
	bool				someone_died;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		philo_mutex;
}						t_global;

int						ft_controller_error_intput(int ac, char **av);

#endif