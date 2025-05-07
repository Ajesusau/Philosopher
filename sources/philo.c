/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:00:01 by anareval          #+#    #+#             */
/*   Updated: 2025/05/07 19:07:17 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **argv)
{
	int	error;

	error = 0;
	if (ft_atoll(argv[1]) <= 0 || ft_atoll(argv[1]) > INT_MAX)
		error = printf("Error: Invalid number of philosophers.\n");
	if (ft_atoll(argv[2]) <= 0 || ft_atoll(argv[2]) > INT_MAX)
		error = printf("Error: Invalid time to die.\n");
	if (ft_atoll(argv[3]) <= 0 || ft_atoll(argv[3]) > INT_MAX)
		error = printf("Error: Invalid time to eat.\n");
	if (ft_atoll(argv[4]) <= 0 || ft_atoll(argv[4]) > INT_MAX)
		error = printf("Error: Invalid time to sleep.\n");
	if (argv[5])
	{
		if (ft_atoll(argv[5]) <= 0 || ft_atoll(argv[5]) > INT_MAX)
		{
			error = printf
				("Error: Invalid number of times each philosopher must eat.\n");
		}
	}
	return (error);
}

int	init_data(char **argv, t_philo *philo)
{
	int	i;
	int	error;

	i = 0;
	error = check_arg(argv);
	philo->num_of_philos = ft_atoll(argv[1]);
	philo->time_to_die = ft_atoll(argv[2]);
	philo->time_to_eat = ft_atoll(argv[3]);
	philo->time_to_sleep = ft_atoll(argv[4]);
	if (argv[5])
		philo->philos_must_eat = ft_atoll(argv[5]);
	else
		philo->philos_must_eat = -1;
	if (error == 0)
	{
		philo->philosopher = malloc(sizeof(pthread_t) * philo->num_of_philos);
		while (i < philo->num_of_philos)
			pthread_create(&philo->philosopher[i++], NULL, &start_philo, philo);
	}
	return (error);
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	philo;

	i = 1;
	if (argc >= 5 && argc <= 6)
	{
		if (init_data(argv, &philo))
			return (EXIT_FAILURE);
		usleep(300);
		printf("num_of_philos: %d\n", philo.num_of_philos);
		printf("time_to_die: %d\n", philo.time_to_die);
		printf("time_to_eat: %d\n", philo.time_to_eat);
		printf("time_to_sleep: %d\n", philo.time_to_sleep);
		printf("philosopher_must_eat: %d\n", philo.philos_must_eat);
		ft_free(&philo);
	}
	else
		printf("Error: Invalid argument count.\n");
}
