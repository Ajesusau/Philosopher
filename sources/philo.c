/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:00:01 by anareval          #+#    #+#             */
/*   Updated: 2025/05/07 19:23:20 by anareval         ###   ########.fr       */
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

void	ini_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		pthread_create
			(&data->philos[i].thread, NULL, &start_philo, &data->philos[i]);
		i++;
	}
}

int	init_data(char **argv, t_data *data)
{
	int	i;
	int	error;

	i = 0;
	error = check_arg(argv);
	data->num_of_philos = ft_atoll(argv[1]);
	data->time_to_die = ft_atoll(argv[2]);
	data->time_to_eat = ft_atoll(argv[3]);
	data->time_to_sleep = ft_atoll(argv[4]);
	data->dead_flag = 0;
	if (argv[5])
		data->philos_must_eat = ft_atoll(argv[5]);
	else
		data->philos_must_eat = -1;
	if (error == 0)
		data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	return (error);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 1;
	if (argc >= 5 && argc <= 6)
	{
		if (init_data(argv, &data))
			return (EXIT_FAILURE);
		printf("num_of_philos: %d\n", data.num_of_philos);
		printf("time_to_die: %d\n", data.time_to_die);
		printf("time_to_eat: %d\n", data.time_to_eat);
		printf("time_to_sleep: %d\n", data.time_to_sleep);
		printf("philosopher_must_eat: %d\n", data.philos_must_eat);
		ini_philo(&data);
		wait_for_philos(&data);
		ft_free(&data);
	}
	else
		printf("Error: Invalid argument count.\n");
}
