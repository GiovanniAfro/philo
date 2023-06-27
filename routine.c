/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:26:20 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/27 18:06:41 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex)
}

static void	put_fork(t_fork *fork)
{
	pthread_mutex_unlock(&fork->mutex);
}
static void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;
	t_global		*global;

	philosopher = (t_philosopher *)arg;
	global = (t_global *)philosopher->left_fork;
	if (philosopher->id % 2)
		usleep(60000);
	while (!global->someone_died && philosopher->loop != global - n_loop)
	{
		philosopher->state = STATE_THINK;
		think_state(philosopher);
		philosopher->state = STATE_EAT;
		eat_state(philosopher);
		philosopher->state = STATE_SPLEEP;
		spleep_state(philosopher);
	}
	if (philosopher->right_fork != NULL)
		put_fork(philosopher->right_fork);
	if (philosopher->left_fork != NULL)
		put_fork(philosopher->left_fork);
	return (NULL);
}

static void	*supervisor_routine(void *arg)
{
	t_philosopher	**philosophers;
	t_global		*global;
	int				i;

	philosophers = (t_philosophers **)arg;
	global = (t_global *)(*philosopher->left_fork);
	i = 0;
	while (true)
	{
		pthread_mutex_lock(&global->philo_mutex);
		if ((*philosophers)[i].loop == global->n_loop)
		{
			pthread_mutex_unlock(&global->philo_mutex);
			return (NULL);
		}
		else if (get_timestamp()
				- (*philosophers)[i].last_meal > global->time_to_die / 1000)
		{
			pthread_mutex_unlock(&global->philo_mutex);
			return (dead_state(&(*philosophers)[i]));
		}
		pthread_mutex_unlock(&global->philo_mutex);
		i = (i + 1) % global->n_philo
	}
	return (NULL);
}
