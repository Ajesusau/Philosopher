/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:00:01 by anareval          #+#    #+#             */
/*   Updated: 2025/04/22 20:18:27 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(char **argv, t_philo *philo)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->philosopher_must_eat = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	philo;

	i = 1;
	if (argc >= 5 && argc <= 6)
	{
		init_data(argv, &philo);
		printf("number_of_philosophers: %d\n", philo.number_of_philosophers);
		printf("time_to_die: %d\n", philo.time_to_die);
		printf("time_to_eat: %d\n", philo.time_to_eat);
		printf("time_to_sleep: %d\n", philo.time_to_sleep);
		printf("philosopher_must_eat: %d\n", philo.philosopher_must_eat);
	}
	else
		printf("Error: Invalid argument count.");
}
