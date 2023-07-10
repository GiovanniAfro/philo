/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:25:16 by gcavanna          #+#    #+#             */
/*   Updated: 2023/07/10 16:06:27 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	parsing_arg(t_info *info, int argc, char *argv[])
{
	info->num_of_philo = ft_get_number(argv[1]);
	info->time_to_die = ft_get_number(argv[2]);
	info->time_to_eat = ft_get_number(argv[3]);
	info->time_to_sleep = ft_get_number(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_get_number(argv[5]);
}

static int	check_info(t_info *info, int argc)
{
	if (argc == 6 && info->num_of_must_eat <= 0)
		return (ft_puterror("ERROR: wrong num of must eat"));
	if (info->num_of_philo < 1)
		return (ft_puterror("ERROR: wrong num of philo"));
	if (info->time_to_die < 60)
		return (ft_puterror("ERROR: wrong time to die"));
	if (info->time_to_eat < 60)
		return (ft_puterror("ERROR: wrong time to eat"));
	if (info->time_to_sleep < 60)
		return (ft_puterror("ERROR: wrong time to sleep"));
	return (FT_SUCCESS);
}

static int	init_philos(t_info *info)
{
	int		i;

	pthread_mutex_init(&info->finish_mutex, NULL);
	if (ft_malloc(&info->philos, sizeof(t_philo) * info->num_of_philo) || \
		ft_malloc(&info->forks, sizeof(pthread_mutex_t) * info->num_of_philo))
		return (ft_puterror("ERROR: malloc failed"));
	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].n = i;
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philos[i].check_mutex, NULL);
		if (i == 0)
			info->philos[i].left = &info->forks[info->num_of_philo - 1];
		else
			info->philos[i].left = &info->forks[i - 1];
		info->philos[i].right = &info->forks[i];
		info->philos[i].info = info;
		++i;
	}
	return (FT_SUCCESS);
}

int	init(t_info *info, int argc, char *argv[])
{
	parsing_arg(info, argc, argv);
	if (check_info(info, argc))
		return (FT_ERROR);
	if (init_philos(info))
		return (FT_ERROR);
	return (FT_SUCCESS);
}



