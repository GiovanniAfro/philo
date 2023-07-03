/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:26:01 by gcavanna          #+#    #+#             */
/*   Updated: 2023/07/03 14:19:08 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_ms_err(char *message)
{
	printf("\n %s\n", message);
	return (1);
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_isdigit(int c)
{
	return ((c >= '0') & (c <= '9'));
}

int	ft_controller_error_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_ms_err("YOU STUPID, wrong number of arguments\n"));
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9' || av[i][0] == '0')
				return (ft_ms_err("\nneed positive args\n"));
			j++;
		}
		i++;
	}
	return (0);
}

t_global	remember_me(t_global *fill)
{
	static t_global	sus;

	if (fill)
		sus = *fill;
	return (sus);
}
