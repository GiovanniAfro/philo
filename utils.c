/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:26:01 by gcavanna          #+#    #+#             */
/*   Updated: 2023/06/20 15:27:53 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_error(void)
{
    printf("\n Wrong input, try again, or die trying\n\n");
    printf("all parameters must be positive integers\n\n");
    printf("'meals' is optional\n\n");
    printf("USAGE: ./philo <number of philosophers> <time to starve> <time to eat> <time to sleep> <meals>\n");
    return (0);
}

int ft_atoi(char *str)
{
    size_t i;
    int num;

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

int ft_isdigit(int c)
{
    return (c >= '0' & c <= '9');
}
int ft_controller_error_intput(int ac, char **av)
{
    int i;

    i = 1;
    if (ac < 5 || ac > 6)
        return (ft_error());
    while (i < ac)
    {
        if (!ft_isdigit(av[i][0]) || ft_atoi(av[i]) < 0 || ft_atoi(av[1]) == 0)
            return (ft_error());
        else if (ft_atoi(av[7]) == 0)
            return (ft_error());
        else if (ft_atoi(av[i]) >= 0 && ft_isdigit(av[i][0]))
            i++;
    }
    return (1);
}