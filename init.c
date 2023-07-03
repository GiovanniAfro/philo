/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:25:16 by gcavanna          #+#    #+#             */
/*   Updated: 2023/07/03 11:51:12 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	*args_init(int ac, char **av)
{
	t_global	args;

	t_global *args = malloc(sizeof(t_global));
	if (args == NULL)
		return NULL;
	args.since_started = 0;
	if (ft_controller_error_intput(ac, av) == 1)
		return (1);
	args.since_started = get_timestamp();
	args.n_philo = ft_atoi(av[1]);
	args.time_to_die = ft_atoi(av[2]);
	args.time_to_eat = ft_atoi(av[3]);
	args.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args.n_loop = ft_atoi(av[5]);
	else
		args.n_loop = -1;
	remember_me(&args);
	return (0);
}

size_t	mutex_init(void)
{
	int			i;
	t_global	args;

	args = remember_me(NULL);
	i = 0;
	args.fork = malloc(sizeof(pthread_mutex_t) * args.n_philo);



