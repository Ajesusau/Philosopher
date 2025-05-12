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

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 1;
	if (argc >= 5 && argc <= 6)
	{
		if (init_data(argv, &data))
			return (EXIT_FAILURE);
		ini_philo(&data);
		wait_for_philos(&data);
		if (data.philos)
			free (data.philos);
	}
	else
		printf("Error: Invalid argument count.\n");
}
