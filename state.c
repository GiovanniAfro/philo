/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:06:40 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/29 12:22:40 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_message(t_global *global, t_philosopher *philosopher,
		const char *message)
{
	pthread_mutex_lock(&global->print_mutex);
	if (!global->someone_died)
		printf("%ld %d %s\n", get_timestamp(), philosopher->id, message);
	pthread_mutex_unlock(&global->print_mutex);
}

static void	*eat_state(void *arg)
{
	t_philosopher	*philosopher;
	t_global		*global;

	philosopher = (t_philosopher *)arg;
	global = (t_global *)philosopher->left_fork;
	print_message(global, philosopher, "is eating🍝");
	take_fork(philosopher->right_fork);
	print_message(global, philosopher, "has taken a fork🍴");
	philosopher->last_meal = get_timestamp();
	usleep(global->time_to_eat);
	put_fork(philosopher->right_fork);
	put_fork(philosopher->left_fork);
	philosopher->loop++;
	return (NULL);
}

static void	*think_state(void *arg)
{
	t_philosopher	*philosopher;
	t_global		*global;

	philosopher = (t_philosopher *)arg;
	global = (t_global *)philosopher->left_fork;
	print_message(global, philosopher, "is sleeping💤");
	usleep(global->time_to_spleep);
	return (NULL);
}

static void	*think_state(void *arg)
{
	t_philosopher	*philosopher;
	t_global		*global;

	philosopher = (t_philosopher *)arg;
	global = (t_global *)philosopher->left_fork;
	print_message(global, philosopher, "is thinking🤔");
	return (NULL);
}

static void	*dead_state(void *arg)
{
	t_philosopher	*philosopher;
	t_global		*global;

	philosopher = (t_philosopher *)arg;
	global = (t_global *)philosopher->left_fork;
	pthread_mutex_lock(&global->death_mutex);
	global->someone_died = true;
	pthread_mutex_unlock(&global->death_mutex);
	print_message(global, philosopher, "died💀");
	return (NULL);
}
